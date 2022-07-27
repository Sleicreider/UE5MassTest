# UE5MassTest
Testing the functionality of the UnrealEngine5 Mass System:

## TODO:

Github formatting

Buggy: Height Tracing disabling doesn't work for Usable Objects.
Position Snapping: Some agents snap to their end position (LoDOff Processor is off tho?)
Agent Avoidance: Disable avoidance if they are blocked too long (Planet Coaster approach)
Reduce force when reenabling avoidance: currently avoidance is disabled for far away LoDs, on reenabling it crowded areas get pushed beyond paths or clip through objects.



## Documentation:

Current UE5 official documentation, therefore here is some of my observations and understandings of parts from the system:
The goal is to create a Roller Coaster Tycoon like crowd, which is running around in a park, using objects or targeting POI (points of interests)
Basic behavior of the agents is done in the State Tree via custom Tasks. 

## Vertex Texture Animation:

The project uses vertex texture animation to gain a lot of performance from agent animations.
For simplicity I used the finished ones from https://github.com/Ji-Rath/MassAITesting
But with correct setup you can use https://github.com/Rexocrates/VAT_Example_Project to generate your own.

## Height calculation:

By default currently a simple (hardcoded values for testing) height tracing processor is running in the background since we don't use collision.
The performance impact is noticeable. It should be disabled when using an object via tagging, which the height processor filters. Atm variable ticktime also impacts the height calculations. Potentially should add a height smoother together with reduced trace frequency.

## Navigation Path:

Currently navigation is done through NavMesh path finding from UE5, I use a StateTreeTask which generates the path points upfront, so we dont query paths all the time, and then it simply follows each point until it reaches its target, with a custom navigation processor.

## State Tree:

StateTree Tasks are not ticked every frame, they tick once their state is active after EnterState() and then need to be signaled again to receive another tick. 
For example a Wait Task can schedule delay signals itself, to receive a second tick where it checks for the time.


![image](https://user-images.githubusercontent.com/8298923/181303272-9d4b03b1-a3bb-4352-87b0-0f93bddfc86f.png)

In cases where you have a Move Player Task and need to wait for the movement to be finished, 
you would just have the Task set the location and have a Processor do the calculations and once the processor is done, 
it can send a Signal to the StateTree again for the Task to receive another tick when it is done.

For example moving to a POI location, you can have a seperate task which checks for a new POI location on EnterState, 
setting the Move fragment’s Center location and it’s other parametners, which are automatically Processed by a Movement Processor.

![image](https://user-images.githubusercontent.com/8298923/181303591-2e057137-6327-4824-9898-046bdc50004e.png)


In a seperate task or just the same tasks’s Tick function you can thecn check if we have reached the location:

![image](https://user-images.githubusercontent.com/8298923/181303684-2df17aeb-b227-4ec6-bd0f-627807643236.png)

The tasks itself doesnt process it every frame so we let our Processor Signal them when the movement is done:

![image](https://user-images.githubusercontent.com/8298923/181304003-9e8aaa3f-8100-4676-8c08-2914a46eb7dc.png)

Here an example for those task in use: 

![image](https://user-images.githubusercontent.com/8298923/181304993-552906f2-645e-4654-bdc0-cfd787b8d266.png)

UDN Developer message about StateTrees:

![image](https://user-images.githubusercontent.com/8298923/181305036-6a30e571-23f9-437a-ba7f-ffd9253a33f4.png)


## Showcase:

Simple Park Testscene - 2k agents
https://user-images.githubusercontent.com/8298923/181391571-799067ff-9d67-4d27-a87c-bf8bf0aabcae.mp4



7k Agents close
https://user-images.githubusercontent.com/8298923/181391734-6fc8be5d-acff-4c9d-96ac-4f3290322be8.mp4



7k Agents far 
https://user-images.githubusercontent.com/8298923/181391798-0f143902-d865-4548-a2f8-c52ccc9c517c.mp4



