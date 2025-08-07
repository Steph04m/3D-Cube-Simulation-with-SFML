# 3D-Cube-Simulation-with-SFML

This project consists in an implementation in C++ of a **Colored 3D Cube** using the **SFML** library.

## Charateristics of the Project
### The Language: Why C++
The main reasons that i chose C++ over other programming languages are two:

 - ***OOP***. While i could have used Processing, it was too easy to do it and it didn't provide a real challenge since many methods are already ready to use. That said, i thought about using C,
but since C++ offers great and fast Data Structures like Vector and it was actually easier to write, i choose C++;
 - The **SFML** library. It's a quite easy library to learn and while I'm far from being an expert, I was able to learn the fundamentals in few days. That said, i've encountered a big problem while
working on this project.

## The Problem: SFML is a 2D library
Exactly, it's a 2D library. Creating a 3D Cube and making it *rotatable* was the real **challenge**. How i managed to do it:

 - The structure of the Cube was created using Vector and some alterations of it included in the SFML library, like Vector3f to create the 24 vertexes. To store them I've used the VertexArray class (included
in the SFML library) and divided the vertexes to create the Cube's faces. It wasn't easy but this was the easiest part.
 -  
 

