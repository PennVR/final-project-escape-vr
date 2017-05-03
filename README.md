# Escape The Room VR

Edward Cai, Alexander Chan, Kelly Tan, Henry Zhu

YouTube link - https://youtu.be/GOWEFWnF0WA

### Techniques used, and why those techniques.

Object pick-up interface - We used Unreal Engine's object pickup interface to power the majority of our object interactions. It allowed us to implement object pickups really quickly, without having to worry about using collision boxes.

Camera Fade - We used camera fade transport the player from the tutorial room to the game room, and from the game room to the win/lose screen. We used this technique because it is a natural transition that is used by other games. 

Sound - Out uses sound effectively and in many scenarios. We got voice actors to voice the guard and the cell mate. The cell mate gives advice, while the guard gives warnings and takes away objects. We also implemented steps that get louder when the guard is closer. Other sounds make our game an immersive VR experience, such as the sounds of flowing water, breaking tables, fire, etc. 

Glow - In our game, objects glow when the player is near, to signal that the object is pickup-able, and hopefully making it a more intuitive experience. 

Collision Boxes - We collision boxes extensively in out game, and it provided most of the logic for the guard checking the cell, and the win conditions. 

AI - We used Unreal Engine's "Blackboard" AI interface to power the guard's movements. The guard even stands in front of the cell randomly to make it harder for the player to time its movements. 

Motion-controller based movement - When the player wins the game, the gate opens and the player must wave his/her controllers in a running motion to run out the prison. We chose this method of movement in order to create urgency and to create a more immersive VR experience. 

Destroyable objects - Many of the objects in the cell, such as the table, are destroyable when thrown as a high velocity against the wall or ceiling. This makes the game more interesting because it creates more scenarios for the player to unlock, and thus making the game more difficult. 

### How to play (using a controller or HMD)

Escape the Room VR can only be played using motion controllers. The player is dropped in a tutorial room where he/she can practice picking up and throwing objects. After practicing. The player is then transported into the jail cell that he/she must escape. The player must then proceed through picking up, breaking, and combining different objects found throughout the jail cell to create a key, which will then be used to unlock the gate and run to freedom. While the player is combining objects, he/she must keep them hidden underneath the bed, or else they face the objects being taken away by the patrolling guard. A jail cell in the next door cell is also giving hints along the way to help in case the player gets stuck.  

### When in VR mode, did you feel any motion sickness? Why and why not?

During our tests, none of the players experienced any motion sickness. This is due to our game's lack of flying and high fps (90+).  

### What was the hardest part of the assignment?

The hardest part of the assignment was mostly debugging object interactions. For a very long time, when the player created fire by rubbing two wooden legs together, the fire would collide with other objects, making a strange bouncing effect. It was also initially impossible to put objects under the bed without them flying out. We encountered many of these small issues while making our game and they were very time consuming to debug. Getting the game into basic working order was pretty straightforward. Since the playing space is so small, we had to make sure the small details such as objects interactions worked perfectly because anything that was a little bit off would ruin the VR experience. 

### What do you wish you’d done differently?

In the primary stages of our project, we wanted to implement climbing as part of the locomotion of our game,  but we found it to be too difficult. If we had more time, we would like to have hidden some objects in the ceiling and forced to player to climb to the top of the wall in order to obtain that object. 

### What do you wish we had done differently?

Our team front-loaded the work for our project, making a very impressive first demo. However, because we had such a complete first demo, our subsequent demos were more about details and immersiveness, which are components of the project that are hard to showcase in a demo. We felt that having so many demos took out the "wow" factor of our project. Perhaps in the future we could give our demos to the instructors so that the other groups have something to look forward to for the final demo. 
