### Assessment for Lab 10

#### Total score: _100.0_ / _100_

Run on March 03, 15:49:30 PM.


### Necessary Files and Structure

+  _10_ / _10_ : Pass: Check that directory "labs" exists.

+  _10_ / _10_ : Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+  _10_ / _10_ : Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		ddadd1ce67798a1afa3491e41f0a11cbbc6f7e1b	refs/heads/devel

		dbfa810fd360c1ec429946e0fb901b28ca57252f	refs/heads/fix/01-compilation-errors

		a598d90919a87027af7ff765a1532bedfca77ac1	refs/heads/master

		e609a1ba32359b46aae81800d4deeda3f8364626	refs/heads/style/02-google-style-errors

		77e59994d4df14bedd715113f38d5e5154b52406	refs/heads/support-code



+  _10_ / _10_ : Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

style/02-google-style-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Sam] 2020-03-02 (HEAD -> devel, origin/devel) Merge branch 'style/02-google-style-errors' into devel 

		[Sam] 2020-03-02 (origin/style/02-google-style-errors, style/02-google-style-errors) style(README.md): style 2 style/02-google-style-errors - made trivial edit to readme to trigger feedback


		[Sam] 2020-03-02 edit of readme to trigger feedback 

		[Sam] 2020-02-26 Merge branch 'style/02-google-style-errors' into devel 

		[Sam] 2020-02-26 style(bus.cc, bus.h, config_manager.cc config_manager.h, data_structs.h       passenger_generator.h, passenger_unloader.cc, passenger_unloader.h       route.cc, route.h): style #2 style/02-google-style-errors - Modified the files above to be google style compliant using cpplint


		[Sam] 2020-02-26 Merge branch 'fix/01-compilation-errors' into devel 

		[Sam] 2020-02-26 (origin/fix/01-compilation-errors, fix/01-compilation-errors) fix(bus.cc, passenger.cc, random_passenger_generator.cc, stop.cc): fix #1 fix/01-compilation-errors - Un-commented code in above files that was preventing compilation via
- make.


		[Sam] 2020-02-26 adding new project/src from lab10 folder 

		[Sam] 2020-02-26 deleting project/src 


		[Sam] 2020-02-26 adding modified passenger_unloader(.h and .cc) so make will compile 


		[Sam] 2020-02-26 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-moexx407 

		[Sam] 2020-02-26 add(lab09): adding lab09 deliverables 



		[Sam] 2020-02-26 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-moexx407 

		[Sam] 2020-02-26 Merge branch 'support-code' 



		[Sam] 2020-02-26 (origin/support-code) Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream into support-code 



















































































		[Sam] 2020-02-20 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-moexx407 

		[Sam] 2020-02-20 push(lab08) lab08_google_tests 




		[Sam] 2020-02-20 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-moexx407 

		[Sam] 2020-02-20 Merge branch 'support-code' 

		[Sam] 2020-02-20 Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream into support-code 











+  _5_ / _5_ : Pass: Check git commit history
Sufficient commits (found=24,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 1)

[OPEN issue #2] :  style/02-google-style-errors [enhancement]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 1)

[CLOSED issue #1] :  fix/01-compilation-errors [bug]





+  _10.0_ / _10_ : Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #2] :  style/02-google-style-errors [enhancement]

[CLOSED issue #1] :  fix/01-compilation-errors [bug]

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+  _10_ / _10_ : Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+  _5_ / _5_ : Pass: Check that file "makefile" exists.

+  _30_ / _30_ : Pass: Check that make compiles.



#### Total score: _100.0_ / _100_

