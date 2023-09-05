# POET (Parameterized Optimizations for Empirical Tuning)
POET is a dynamic scripting language designed to apply transformations 
to source code written in an arbitrary programming language. 
POET was originally designed for the purpose of parameterizing 
performance optimizations so that the optimized code may be 
empirically tuned to attain the best performance on a wide 
variety of different HPC platforms. The use of POET, however, 
is not limited to code optimizations. You can use POET to easily 
read in any structured input, extract information from 
or apply transformations to the input,  and then output the result. 
Check other tutorials  for existing examples and applications 
for the POET language.  If you are a new user of the POET language,
please send us a brief description of your project and what roles
POET has played in your project. We appreciate your input and any
feedback you may have in the design and implementation of POET.
The POET language was designed and implemented by Dr. Qing Yi
at the University of Texas at San Antonio.  All questions and 
feedbacks should be directed to her at qyi@uccs.edu.

The current release of POET includes five directories: *src*, *lib*, *doc*, *test*, 
and *examples*. The *src* directory contains C/C++/Yacc/Lex code for the POET 
language interpreter; the *lib* directory contains the existing POET libraries 
that include an extensive collection of language descriptions and program 
transformation routines useful both for software optimization and evolution;
the *doc* directory contains documentations about the POET language;
the *test*  directory contains some example applications of the POET code; 
and the *examples* directory contains some stand-alone POET code that 
serve as examples in POET tutorials. 

## Authors
Qing Yi   qyi@uccs.edu

## Contribution guidelines

- You can report issues/bugs/typos in the `Issues` tab on Github. Please provide as much information as possible, e.g., steps to recreate bug, expected behavior, etc.
- If you'd like to contribute to the POET repository, first configure git's default hooks directory on your local machine to use the git hooks located in this repository's *hooks* directory:
  * `find .git/hooks -type l -exec rm {} \;`
  * `find hooks -type f -exec ln -sf ../../{} .git/hooks/ \;`
- Do not work on the `master` branch. It's suggested you fork this repository to your personal account and create feature branches to work on
- Make sure each commit can stand on its own and can be rolled-back independent from other commits
- When ready for review, squash your commits if needed using `git rebase -i` to retain only the most significant commit(s). Doing this makes reverting bad commits easier and keeps the git history free of nonessential commits
- Make sure to test any code changes
  * `make check` manually to run tests
  * `git push` will run the pre-push hook which runs tests and halts the push operation if any test fails
- Open a pull request (PR). Try to keep each PR limited in scope and goal
- When PR is approved for merging by reviewers, do one final rebase to squash any extraneous commits before merging

## License
   POET : Parameterized Optimizations for Empirical Tuning
   Copyright (c)  2008,  Qing Yi.  All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met: 

 1. Redistributions of source code must retain the above copyright notice, 
    this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice, 
    this list of conditions and the following disclaimer in the documentation 
    and/or other materials provided with the distribution.
 3. Neither the name of UTSA nor the names of its contributors may be used to 
    endorse or promote products derived from this software without specific 
    prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
OF THE POSSIBILITY OF SUCH DAMAGE.
