/**
 * @file mainpage.h
 *
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

 /*! \mainpage Index Page - CSCI3081 moexx407
 *
 * \section intro_sec Introduction
 *
 *   This is the main page for Sam Moe's Bus Simulation project for CSCI 3081
 * Spring 2020. This Simulation is intended to model the Bus system at the
 * University of Minnesota. The Program provides a visual simulation of busses
 * moving along routes across the University's campus. These routes consist of
 * stops at which passengers with desired destinations are generated
 * periodically. The busses move along the routes and pick up passengers, so
 * long as they have room to fit more passengers. At each stop a given bus stops
 * at, any passengers on the bus whose desired destination is that stop are
 * unloaded. As the simulation progresses, relevant statistical information
 * about busses are written to a new CSV file called BusData.csv, and similarly
 * information about passengers is written to PassData.csv. This information
 * can be used to perfor further statistical analysis of the simulation.
 *
 * \section instructions_sec Instructions For Obtaining, Configuring, Compiling and Executing the Simulation
 *
 *   To obtain the program: Navigate to the base project directory (project/)
 * Then, to compile the program, navigate to the project/src directory and
 * execute the 'make' command. Once compiled, we are ready to run simulation.
 * To run the simulation, swtich back into the project directory. You will need
 * a valid port number above 8000 to execute the simulation using the server.
 * Using the port number of your choice, execute the command
 * ./build/bin/vis_sim <port_number>. This will start the server through which
 * the program communicates with the visual representation on your browser. Once
 * the server has initialized, copy the following URL into your browser's search
 * bar <http://127.0.0.1:<port_number>/web_graphics/project.html> but replace
 * <port_number> with the port you chose earlier. When you hit enter, you will
 * see the visual representation of the University of Minnesota Campus and it's
 * bus routes. There are a series of sliders on the top left of the simulation.
 * The top slider allows you to set the number of time steps that will occur
 * before the simulation has completed. Each additional slider allows the user
 * to set the number of time steps that will occur bewteen busses for each route
 * in the simulation (there will be a slider for each route in the simulation).
 * Below the sliders there is a start button that, when pressed, will start the
 * simulation. Below the start button there is a pause button that allows the
 * user to toggle between an active state where the simulation is running and a
 * paused state where the simulation remains in a constant state and time stops.
 *
 * \section discussion_sec Discussion of Design and Implementation of the Factory Class
 *   In this section I will discuss my idea for the design and implementation of
 * the BusFactory class. The general purpose of creating a Factory for Busses
 * rather than simply creating busses directly is to extend to robustness of
 * the program. It would be possible to just create busses directly, but there
 * could be situations where we want to create a specific type of bus but may
 * not know which type of bus we want or need. This is where the factory comes
 * in. The BusFactory allows for the creation of busses where the type of bus
 * that is created is determined by the BusFactory and not the specific type of
 * bus object itself. In my implementation of the BusFactory, I chose to make a
 * factory that randomly generates either a SmallBus, MediumBus, or LargeBus.
 * The factory uses a psuedo-random algorithm to obtain a value and this value
 * is what determines which specific type of bus will be created. The BusFactory
 * has a signle method, CreateBus(), whichreturns a pointer to a new bus. Inside
 * of this method is where the random value is generated and also where the
 * conditionals that use the random value to determine which type of bus to
 * create are located. I have yet to implement the BusFactory into the
 * visualization simulator, but when I do, it will be implemented within the
 * VisualizationSimulator::Update() method. Within this method is where it is
 * determined if we need to create any new busses. If it is decided that we
 * are in need of new busses, the BusFactory method CreateBus() can be called
 * and the fields of the bus can be set using the existing bus information in
 * the Update method (inbound and outbound routes and speed).
 *   One pro of my solution is that it allows for easy extension. If we create
 * another new type of bus, the CreateBus() method can easily be changed to
 * accommodate this new type of bus. You can accommodate an additional bus
 * simply by altering the random value generation to allow for one additional
 * random value, and then adding a conditional that creates the new type of bus
 * whenever the new random value has been generated.
 *   One con of my solution is that it doesn't allow us to create busses of
 * a specific type. Since the type of bus is randomly selected this version of
 * the bus factory isn't able to specifiy the creation of, for example, a large
 * bus.
 *  One way we could make this possible is to use an abstract factory. This
 * abstract factory would provide an interface for creating families of objects
 * without specifying their concrete classes. This solution would allow us to
 * actually create specific types of objects when they are needed. Another
 * possible implementation would be to create an abstract factory capible of
 * producing multiple concrete factories. These concrete factories could then
 * be capible of creating specific types of objects rather than random ones.
 * A pro of this solution would be that we are actually able to create objects
 * of a specific type. One con of this solution would be that having a factory
 * which creates factories can be a much harder concept to grasp and
 * implement so this solution would require additional time and effort.
 *
 * \section observer_sec Designing and Implementing the Observer Pattern
 *  As an enhancemenet to the simulation, we wanted to add functionality that
 * would allow us to actively view information about busses, stops and
 * passengers as the simulation progresses. In order to do this, I utilized the
 * observer pattern. I began by creating an IObserver class. This class is an
 * interface and thus cannot be insantiated. It contains a Notify method which
 * is pure virtual and specifies the  Notify method that will be overridden
 * in children of IObserver (the children are the actual concrete Observers that
 * will be doing the real observing). Next, I created an IObservable class which
 * represents the interface for the acutal subjects (ie what will be observed).
 * IObservable contains three methods: RegisterObserver, ClearObservers, and
 * NotifyObservers. RegisterObserver is used to add a given observer to the
 * list of observers. When an observer is added to the list, then whenever the
 * object (bus) that it is observing experinces a change in state, the observer
 * will be notified by the observable (the bus being observed). This is done via
 * NotifyObservers. The ClearObservers method is used to clear all current
 * observers from the observer list. Once IObservable was created, I extended
 * my bus class to inherit IObservable. This makes sense becasue the busses are
 * what we want to observe, and so bus and its children, SmallBus, MediumBus,
 * and LargeBus, will all have access to the IObservable methods. After this, I
 * added an AddListenerCommand to the my_web_server_command files. This command
 * has a method called execute which does the actual work of the command.
 * Execute calls the VisualizationSimulator to delete current observers, creates
 * a new BusWebObserver (a child of IObserver and thus an observer) and calls
 * the VisualizationSimulator AddListener method. This method, which resides in
 * the VisualizationSimulator class, identifies the desired bus which we want
 * to observe and calls the RegisterObserver method with the observer we want to
 * observe the bus as an argument. This adds the observer to the list of
 * observers. Finally, I modified the busses Update method to call the bus's
 * NotifyObservers method. This way, every time the simulation is updated, each
 * bus will notify its observer of any changes in info, and the preceeding
 * functions will notify the web server and make this information appear on the
 * screen. My observer pattern allows you to hover over any busses or stops in
 * the simulation and see basic information about them. Additionally, if you
 * clock on a stop or bus, you will see more information in the box on the right
 * side of the simulation.
 * \section decorator_sec Designing and Implementing the Decorator Pattern
 *  For my simulation I attempted to implement the decorator pattern in order to
 * change the color of individual busses without affecting other busses. The
 * decorator that I intended to implement would have required that a color
 * variable be added to the Bus class, along with setters and getter for this
 * variable. Additionally, the bus class would have been made abstract by making
 * the SetColor() function pure virutal. This means that the bus subclasses
 * would have overridden this function in order to set colors in their own ways.
 * Included in my src folder are the classes bus_decorator.h, gold_bus.h, and
 * maroon_bus.h, all of which are commented out. The BusDecorator class was
 * intended to serve as the decorator and would adhere to the interface set up
 * by what would have been an abstract Bus class. The BusDecorator class is the
 * class that provides the base implementations of the pure virtual function in
 * it's parent, the Bus class. The MaroonBus and GoldBus classes serve as the
 * concrete decorators in the pattern. They would further override the base
 * implementation of the SetColor() function in order to actually change the
 * color to either maroon or gold. With these classes, it would have been
 * possible to Update the current_route_ field of Bus and then decorate each
 * bus when it begins either an incoming or outgoing route by checking the
 * current route variable.
 *   One pro of the version of the decorator pattern I attempted to implement
 * is that it makes for easy extension. For each color we would have wanted to
 * decorate the bus, we would simply need to copy either maroon_bus.h or
 * gold_bus.h and simply change the names to the desired color and change the 4
 * tuple representing the color to have values describing our new color. This
 * also makes for high cohesion because each color to be decorated resides in
 * its own decorator class. One con of my implementation is that it does not
 * allow for easy extension had we wanted to decorate a different aspect of the
 * bus. My implementation relies on the fact that the bus class has a color
 * variable. If I wanted to change the shape of the bus, my decorator pattern
 * would have to change significantly.
 *  One alternative strategy I could have used would have been to have one
 * concrete decorator called ColorDecorator. Then, rather than having a
 * a different class for each color we wish to decorate our busses, we could
 * let the ColorDecorator class handle which color to use. Since the
 * concrete decorators are descendants of the bus class, it would have then been
 * possible to determine which route the bus is on from inside of the decorator
 * class and so ColorDecorator could color any bus the correct color based on
 * the busses current state. A pro of this implementation is that it would have
 * lower coupling since we wouldn't need to have multiple concrete decorators.
 * It would also allow for easier extension becasue we wouldn't need to create a
 * new class for each new color. One con of this implementation would be that
 * cohesion would be lower since many different colors could be represented in
 * the one ColorBus class.
 *  Another alternative implementation of the decorator pattern would be to use
 * decorators to create Small, medium or large busses when the new busses
 * are created. In my current program, these different sized busses are simply
 * children of the Bus parent class. I could have instead implemented the
 * decorator pattern so that each of the different bus sizes was a concrete
 * decorator. Then, when the new busses are being created, we could simply
 * decorate a base Bus with the desired size decorator and the bus would then
 * have the correct capacity.
 */

#endif  // SRC_MAINPAGE_H_
