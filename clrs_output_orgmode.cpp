#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>


using std::vector;
using std::string;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

void write_org_header(const string &title, unsigned no, ofstream &ofs)
{
  string description = "Introduction to Algorithms Chapter-" + to_string(no);
  string header = "#+BEGIN_COMMENT\n.. title: "
    + title
    + "\n.. slug: "
    + title
    + "\n.. date: 2018-04-25 13:30:12 UTC+08:00\n.. tags: C++,CLRS\n.. category: CLRS\n.. link:\n.. description: "
    + description
    + "\n.. type: text\n#+END_COMMENT\n\n#+OPTIONS: ^:{}";
  ofs << header << "\n\n";
}

bool is_utilities_file(const string &file_name)
{
  if(file_name.find("utilities") != string::npos)
    return true;
  else
    return false;
}

void write_utilities_file(const string &file_path, ofstream &ofs)
{
  static const string git_repo =
    "https://github.com/zero4drift/CLRS_Cpp_Implementations/tree/master/";
  auto index = file_path.find("include");
  ofs << "* utilities\n\n  " << git_repo << file_path.substr(index) << "\n\n";
}

bool is_include_using_ifndef_line(const string &line)
{
  return (line.find("#include <") != string::npos)
    || (line.find("using std") != string::npos)
    || (line.find("#ifndef") != string::npos)
    || (line.find("#define") != string::npos)
    || (line.find("#endif") != string::npos);
}

void handle_cpp_file(ifstream &ifs, ofstream &ofs)
{
  string line;
  ofs << "#+begin_src c++\n";
  while(ifs)
    {
      getline(ifs, line);
      if(!line.size() || is_include_using_ifndef_line(line)) continue;
      ofs << "  " << line << "\n";
    }
  ofs << "#+end_src\n\n";
}

vector<string> handle_cpp_files(const string &project_root, unsigned chapter_no, ofstream &ofs)
{
  vector<string> vs;
  ifstream ifs;
  string file_name, file_path;
  string chapter_path = project_root + "/chapter-" + to_string(chapter_no);
  for(boost::filesystem::recursive_directory_iterator end, dir(chapter_path);
      dir != end; ++dir)
    {
      file_name = dir->path().filename().native();
      file_path = dir->path().native();
      if(boost::filesystem::is_directory(dir->path()))
	{
	  ofs << "* " + file_name + "\n\n";
	  vs.push_back(file_name);
	}
      else if(is_utilities_file(file_name))
	write_utilities_file(file_path, ofs); 
      else
	{
	  ifs.open(file_path);
	  handle_cpp_file(ifs, ofs);
	  ifs.close();
	}
    }
  return vs;
}

int main()
{
  string title;
  string project_root;
  cout << "Specify project root path: ";
  cin >> project_root;
  unsigned first, last;
  cout << "Specify first chpater and last chapter number: " << endl;
  cin >> first >> last;
  string chapter_path;
  string output_path;
  ofstream ofs;
  while(first <= last)
    {
      string title = "CLRS-Cpp-Implementations-Chapter-" + to_string(first);
      output_path = project_root + title + ".org";
      ofs.open(output_path, ofstream::app);
      write_org_header(title, first, ofs);
      auto vs = handle_cpp_files(project_root, first, ofs);
      for(const auto &s : vs)
	ofs << s << " ";
      ++first;
      ofs.close();
    }
}
