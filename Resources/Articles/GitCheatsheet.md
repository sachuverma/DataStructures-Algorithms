
## Git cheatsheet

Git is software for tracking changes in any set of files, usually used for coordinating work among programmers collaboratively developing source code during software development. Its goals include speed, data integrity, and support for distributed, non-linear workflows.

As a coder, at some point in time, you will need Git, and once you start using it, you won't stop, even though it could get frustrating at times. So here is a cheat sheet you can use when you are revisiting Git after a long time, or want to learn more applications of Git, or if you need to time travel and get your older code back.


Before we dive in, let me explain the structure of Git so that you can understand the commands better.


[Repositories](https://docs.github.com/en/repositories/creating-and-managing-repositories/about-repositories): They are a collection of files of various versions of a Project.

[Remote repository](https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories): The current repo that is stored remotely/online. So the repos we see on Github or Gitlab website are the remote repos for those projects. They contain the changes made and pushed by everyone.

[Local repository](https://stackoverflow.com/questions/13072111/gits-local-repository-and-remote-repository-confusing-concepts): The current repo that is stored on your local device. It contains the changes made by you and can also include the changes present on the remote repo.

[Commits](https://docs.github.com/en/github/committing-changes-to-your-project/creating-and-editing-commits/about-commits): They essentially represent versions of a codebase. Each commit contains changes concerning the last state of the repo.

[Branches](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-branches): A branch represents an independent line of development. When we create a branch, we sort of create a brand new working directory, staging area, and project history. New commits are recorded in the history of the current branch then.
  
**1) git config**

Let's start with setting up our environment for Git. Run these commands on your terminal to set the configuration of Git globally(for all future repositories). 
```bash
$ git config --global user.name "John Doe"
$ git config --global user.email "johndoe@email.com"
```
**2) git init**

Next, we need to initialize a folder as a git repository. This command actually creates a .git hidden folder inside your folder. This folder signifies that it is a git repo and stores the metadata required by Git.

```bash
# Run the following command inside the folder
$ git init
# Run the following command to create a new directory that is a git repo
$ git init DIRECTORY_PATH/DIRECTORY_NAME
```
**3) git clone**

If you want to use an already existing git repo(remote repo), you need to create a copy of it on your local device first(local repo). For that, we use the clone command. First, copy the cloning link of that repo(this is usually present where the remote repo is stored).
```bash
$ git clone LINK
$ git clone https://github.com/sachuverma/DataStructures-Algorithms
```

**4) git fetch**

The command git fetch downloads the remote repository details and changes on your device
```bash
$ git fetch 
# fetch for just one branch
$ git fetch <remote> <local> 
# <remote> is the name of the remote branch
# <local> is the name of the local branch
# an example of it is 
$ git fetch origin master
```
**5) git pull**

The pull command is used to access the changes (commits)from a remote repository to the local repository. 
Git pull is a mix of two commands git fetch + git merge. When we used Git fetch earlier, it downloaded the current state of the remote repository first to our local device. But our files are not changed yet. To bring the changes to our file, we need git merge, which updates our local files based on the remote version.

```bash
$ git pull <option> [<repository URL><refspec>...]  
```
**6) git status**

The git status command displays the state of the working directory and the staging area. It lets you see which changes have been staged, which haven't, and which files aren't being tracked by Git.
```bash
$ git status 
# a sample output of this command is as follows
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	README.txt
	lab1
```

**7) git add**

The git add command adds a file to the Git staging area. This area contains a list of all the files you have recently changed
```bash
$ git add /path-to-test-py/test.py
```
If you need to delete a file or folder, you can check out the [git rm](https://www.git-tower.com/learn/git/commands/git-rm) command.

**8) git commit**

Now that we have added or deleted the changes we need to inform Git about, we commit the changes. This, in a way, finalized the next version of our codebase. We can go back to all the past commits to see the version history. The command works as follows.
```bash
$ git commit -m "The message you want to write to describe this commit"
```

**9) git push**

Till now, whatever we were doing was happening to our local repository, but at some point, we needed to push it to the remote repository as well so that others could see and use our code. The git push command does this.
```bash
$ git push <remote> <local> 
# <remote> is the name of the remote branch
# <local> is the name of the local branch
# Example
$ git push origin master
```

**10) git log**

After performing multiple commits, we will actually want to look at how the code has evolved. As we will learn ahead, there are also chances that many people make commits to their branch and at some point might want to merge their branch with a different branch. All such actions that have been done in our repo can be accessed using the git log command
```bash
$ git log --graph --oneline --decorate
# a sample output
*   0e25143 (HEAD, main) Merge branch 'feature'
|\  
| * 16b36c6 Fix a bug in the new feature
| * 23ad9ad Start a new feature
* | ad8621a Fix a critical security issue
|/  
* 400e4b7 Fix typos in the documentation
* 160e224 Add the initial code base
```

**11) git revert**

git revert can be described as the undo button, but a smart one. It doesn't just go back in time but brings the past changes into the next commit so that the unwanted changes are still a part of the version history.
For git revert, we will need the commit codes that we saw earlier in the log.      

```bash
$ git log --oneline
86bb32e prepend content to demo file
3602d88 add new content to demo file
299b15f initial commit
$ git reset --hard c14809fa
# this command will not changes files that you have not git added 
```

**12) git branch**

This command lets us create, list, rename, and delete branches. Let's look at a few examples.
```bash
# this lists the name of the branches present
$ git branch 
main 
another_branch 
feature_inprogress_branch
# delete a branch safely
$ git branch -d <branch>
$ git branch -d another_branch
```

**13)Git checkout**

The git checkout command lets you navigate between the branches created by git branch.
```bash
$ git checkout <branch_name>
$ git checkout another_branch
# create a new branch
$ git checkout -b <new_branch_name>
$ git checkout -b new_feature_branch
```


**14) git diff**

There are times when we will need to compare the code between versions or between branches; that is when we use git diff.
```bash
# print any uncommitted changes since the last commit.
$ git diff
# compare code between two branches
$ git diff branch1 branch2
# print the uncommitted changes made in one file
$ git diff /filepath/filename
```

**15) git rebase**

Rebase is one of two Git utilities that specializes in integrating changes from one branch onto another. The other change integration utility is git merge. Merge is always a forward-moving change record. Alternatively, rebase has powerful history rewriting features.
Let's see a visual of what git rebase does.

```bash
  B -- C (another_branch)
   /      
  A--------D (master)
Rebasing another_branch onto master
             
             B -- C (another_branch)
            /      
  A--------D (master)
```
The corresponding code

```bash
$ git pull origin master
$ git checkout another_branch
$ git rebase master
```
