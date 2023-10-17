# PRINTF COLLABORATION

<h3>Collaborators</h3>
<ul>
<li><a href="https://github.com/briviamoon/">Brivia Allan</a><li>
  <li><a href="https://github.com/larinegit/">Larine Omoit</li>
<\-- am the second collaborater -->
</ul>

# Repo-creation

- Partner A crates a repository named printf.

- Partner A then invites Partner B to collaborate on github

 1. Go to github settings in the printf repository.
 2. Choose Add Collaborator.
 3. Enter a github user name or email belonging to your partners github.

- Partner B accepts the invite on emeil or github.

- Partner B then proceeds to clone The repo created by Partner A

### on cloning

 1. Partner B uses their own Git hub Token as they would any other repository.
 (this is possible beacause collaborators have push authentication granted for the project repo)
 2. Partner B : on successfull cloning, Creates a branch.

- In good practice, branches have the format of ```git chechout -B <NAME-OF-PARTNER/FEATURE-EDITED>```

 4. Partner B commits the changes and pushes. ```git push origin <BranchName>```
 5. Partner B goes to github repo on Github and choose create a pull request.
 6. Partner B gives a detailed description of the added feature and confirms to create a pull request.
 7. Partner Reviews the changes and comments, requests for change or aprooves comments and merges the commit to main.
 8. Both Partner ```git pull``` to ensure updates are current on the local environments
 9. The commit process and review goes both ways.
# TASK 0
- 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
mandatory
Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
You don’t have to reproduce the buffer handling of the C library printf function
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

# In the spirit of Collaboration, Happy Coding

