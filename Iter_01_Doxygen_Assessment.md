### Iteration 1 - Doxygen Partial Assessment (Graded By: Suhail Alnahari)

Run on March 28, 18:47:59 PM.

<hr>

This Partial Assessment indicates a TA has begun grading your Doxygen-generated documentation. However, documentation will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's documentation has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 1 final submission.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Doxygen Tests

+ Pass: Change into directory "project/docs".

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that file "html/index.html" exists.

+ Pass: Inspecting Doxygen webpages...



<hr>

This Partial Assessment indicates a TA has begun grading your branches and issues. However, this will be graded using a tallying spreadsheed and grades will only be posted to Canvas once every student's branches and issues have been graded. We ask for your patience at this time.

  Please note: Branches are counted throughout Iteration 1. We are looking for branches you made and left alone during Iteration 1. Issues however are counted for the entirety of the semester. We ran into some glitches automatically grading this, so this is the solution we came up with.

<hr>

+ Pass: Configuring GHI

+  _2_ / _2_ : Pass: This test counts the number of branches made during development of Iteration 1

Sufficient branches found (found=13, required=8):

Doc/08-new-route-iteration-1-3

Refactor/07-cleanup-code

doc/13-updated-doxygen-documentation

feature/09-bus-factory

feature/10-pause-button

feature/11-skip-stop-functionality

fix/01-compilation-errors

style/02-google-style-errors

style/12-google-style-check

test/03-passenger-tests

test/04-stop-tests

test/05-route-tests

test/06-bus-tests

+  _2.0_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 10, Expected: 8) 

 [OPEN issue #9] :  feature/09-bus-factory [enhancement]

[OPEN issue #5] :  test/05-route-tests [enhancement]

[CLOSED issue #11] :  feature/11-skip-stop-functionality [enhancement]

[CLOSED issue #10] :  feature/10-pause-button [enhancement]

[CLOSED issue #8] :  Doc/08-new-route-iteration-1-3 [enhancement]

[CLOSED issue #7] :  Refactor/07-cleanup-code [bug]

[CLOSED issue #4] :  test/04-stop-tests [enhancement]

[CLOSED issue #3] :  test/03-passenger-tests [enhancement]

[CLOSED issue #2] :  style/02-google-style-errors [enhancement]

[CLOSED issue #1] :  fix/01-compilation-errors [bug]

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Sam] 2020-03-24 (HEAD, tag: iteration1-final-devel, origin/devel) Merge branch 'doc/13-updated-doxygen-documentation' into devel 

		[Sam] 2020-03-24 (origin/doc/13-updated-doxygen-documentation, doc/13-updated-doxygen-documentation) doc( bus_factory.h, bus.h, large_bus.h mainpage.h medium_bus.h passenger_factory.h, passenger_generator.h, passenger_loader.h, passenger_unloader.h, passenger.h, random_passenger_generator.h, route.h, small_bus.h, stop.h): doc #13 doc/13-updated-doxygen-documentation -Added doxygen documentation for new methods and classes to all .h files
-Added a mainpage.h with information on how to use the program and
  discussion of my implementation of a factory, its pros and cons, and
  possible alternative solutions.


		[Sam] 2020-03-24 Merge branch 'style/12-google-style-check' into devel 

		[Sam] 2020-03-24 (origin/style/12-google-style-check, style/12-google-style-check) style (main.cpp, my_web_server_command.h/.cc, my_web_server_session_state.h/.cc, my_web_server_session.h/.cc, my_web_server.h/.cc, visualization_simulator.h/.cc. web_interface.h): style #12 style/12-google-style-check -Used cpplint to check all .cc and .h files in both /src and /web
folders.


		[Sam] 2020-03-24 Merge branch 'feature/11-skip-stop-functionality' into devel 

		[Sam] 2020-03-24 (origin/feature/11-skip-stop-functionality, feature/11-skip-stop-functionality) feature(src/bus.cc): feature #11 feature/11-skip-stop-functionality -Added print statements inside of move() function in bus.cc which
indicates the number of any stop that has been skipped due to no
passengers getting on or off.


		[Sam] 2020-03-24 Merge branch 'feature/10-pause-button' into devel 

		[Sam] 2020-03-24 (origin/feature/10-pause-button, feature/10-pause-button) feature (web_code/web/main.cpp,  web_code/web/my_web_server_command.h/.cc,  web_code/web/visualization_simulator.h/.cc,  web_graphics/sketch.js): feature #10 feature/10-pause-button -Added functionality for a pause button that allows the user to pause
and resume the program. The button works by modifying a boolean in
the VisualizationSimulator class called paused and if the button is
pressed the boolean is switched to the opposite. In the update function,
if pause == true, the program does not update.


		[Sam] 2020-03-24 Merge branch 'feature/09-bus-factory' into devel 

		[Sam] 2020-03-24 (origin/feature/09-bus-factory, feature/09-bus-factory) feature(bus_factory.h/.cc, large_bus.h/.cc, medium_bus.h/.cc, small_bus.h/.cc, bus.h/.cc): feature #9 feature/09-bus-factory -Added child classes (small, medium, and large busses)
-Added a passenger factory class which randomly creates either a small,
medium, or large bus.
- Added a constructor in the bus class that allows for one parameter
(the size of the bus)


		[Sam] 2020-03-23 Merge branch 'Doc/08-new-route-iteration-1-3' into devel 

		[Sam] 2020-03-23 (origin/Doc/08-new-route-iteration-1-3, Doc/08-new-route-iteration-1-3) Doc(project/config/confix.txt): Doc #8 Doc/08-new-route-iteration-1-3 -Adding a new route to file config.txt in the directory project/config
-The outbound route goes from Northrop to Sanford Hall
-The inbound route goes from Sanford Hall to Northrop


		[Sam] 2020-03-23 Merge branch 'Refactor/07-cleanup-code' into devel 

		[Sam] 2020-03-23 (origin/Refactor/07-cleanup-code, Refactor/07-cleanup-code) Refactor(passenger_loader.cc, passenger_loader.h, route.cc, route.h): Refactor #7 Refactor/07-cleanup-code -Changing indentation in Bus class
-Change definition of PassengerLoader::LoadPassenger() so it returns bool
-Refactor naming: Change Route::NextStop to Route::ToNextStop


		[Sam] 2020-03-23 Merge branch 'support-code' into devel 

		[Sam] 2020-03-23 (origin/support-code) Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-s20/repo-moexx407 into support-code 

		[Sam] 2020-03-23 Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream into support-code 

		[Sam] 2020-03-23 commit cloned repo 






		[Sam] 2020-03-06 (tag: Iter1D2) Merge branch 'test/05-route-tests' into devel 

		[Sam] 2020-03-06 (origin/test/05-route-tests, test/05-route-tests) test(route_UT.cc): test #5 test/05-route-tests -Added unit tests for route class methods


		[Sam] 2020-03-06 Merge branch 'test/06-bus-tests' into devel 

		[Sam] 2020-03-06 (origin/test/06-bus-tests, test/06-bus-tests) test(bus_UT.cc) fix #6 fix/06-bus-tests - Added unit tests for bus class functions


		[Sam] 2020-03-06 Merge branch 'test/04-stop-tests' into devel 

		[Sam] 2020-03-06 (origin/test/04-stop-tests, test/04-stop-tests) test(stop_UT.cc): test #4 test/04-stop-tests - Added tests for Stop class functions


		[Sam] 2020-03-06 Merge branch 'test/03-passenger-tests' into devel 

		[Sam] 2020-03-06 (origin/test/03-passenger-tests, test/03-passenger-tests) test(passenger_UT.cc): test #3 test/03-passenger-tests -Added unit tests for functions in the passenger class














		[Sam] 2020-03-02 Merge branch 'style/02-google-style-errors' into devel 


		[Sam] 2020-03-02 (origin/style/02-google-style-errors, style/02-google-style-errors) style(README.md): style 2 style/02-google-style-errors - made trivial edit to readme to trigger feedback



		[Sam] 2020-03-02 edit of readme to trigger feedback 


		[Sam] 2020-03-02 Merge branch 'support-code' 

		[Sam] 2020-03-02 Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream into support-code 

		[Sam] 2020-03-02 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-moexx407 
























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



		[Sam] 2020-02-26 Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream into support-code 







































+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=77,required=15)

