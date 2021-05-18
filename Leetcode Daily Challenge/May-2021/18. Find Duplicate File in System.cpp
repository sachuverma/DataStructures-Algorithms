/*
Find Duplicate File in System
=============================

Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
"directory_path/file_name.txt"

Example 1:
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

Example 2:
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]

Constraints:
1 <= paths.length <= 2 * 104
1 <= paths[i].length <= 3000
1 <= sum(paths[i].length) <= 5 * 105
paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.

Follow up:
Imagine you are given a real file system, how will you search files? DFS or BFS?
If the file content is very large (GB level), how will you modify your solution?
If you can only read the file by 1kb each time, how will you modify your solution?
What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
How to make sure the duplicated files you find are not false positive?
*/

class Solution
{
public:
  vector<vector<string>> findDuplicate(vector<string> &paths)
  {
    unordered_map<string, vector<string>> groupByContent;
    vector<vector<string>> ans;

    for (auto &path : paths)
    {
      string mainPath, fileName, fileContent;
      string curr = "";
      int i = 0;
      while (i < path.size() && path[i] != ' ')
        curr += path[i++];
      i++;

      mainPath = curr;
      while (i < path.size())
      {
        curr = "";
        while (i < path.size() && path[i] != '(')
          curr += path[i++];
        i++;
        fileName = curr;
        curr = "";

        while (i < path.size() && path[i] != ')')
          curr += path[i++];
        i++;
        fileContent = curr;
        i++;

        string fullFilePath = mainPath + "/" + fileName;
        groupByContent[fileContent].push_back(fullFilePath);
      }
    }

    for (auto &groups : groupByContent)
    {
      // cout<<groups.first<<endl;
      if (groups.second.size() > 1)
        ans.push_back(groups.second);
      // for(auto &i: groups.second) cout<<i<<" ";
      // cout<<endl<<endl;
    }

    return ans;
  }
};
