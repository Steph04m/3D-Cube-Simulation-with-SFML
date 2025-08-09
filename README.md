# 3D-Cube-Simulation-with-SFML

This project consists in an implementation in C++ of a **Colored 3D Cube** using the **SFML** library.

## Charateristics of the Project
### The Language: Why C++
The main reasons that I chose C++ over other programming languages are two:

 - ***Absolute OOP*** (@BoredDam). While I could have used Processing, it was too easy to do it and it didn't provide a real challenge since many methods are already ready to use. That said, i thought about using C, but since C++ offers great and fast Data Structures like Vector and it was actually easier to write, I choose C++;
 - The **SFML** library. It's a quite easy library to learn and while I'm far from being an expert, I was able to learn the fundamentals in few days. That said, I've encountered a big problem while
working on this project.

### The Problem: SFML is a 2D library
Exactly, it's a 2D library. Creating a 3D Cube and making it *rotatable* was the real **challenge**. How I managed to do it:

 - The structure of the Cube was created using Vector and some alterations of it included in the SFML library, like Vector3f to create the 24 vertexes. To store them I've used the VertexArray class
 (included in the SFML library) and divided the vertexes to create the Cube's faces. It wasn't easy but this was by far the easiest part.
 - To rotate the Cube I created multiple methods, some of them to make the rotation itself and some others to display the Cube correctly.
 - Since SFML is a 2D library, it lacks a Z-buffer, so simulating depth was a big challenge. To solve the problem I've used the Painter's Algorithm.

### Simulating Depth: How the Painter's Algorithm works and why I chose it
I chose the Painter's Algorithm over other algorithms for two main reasons:

- *Simplicity.* The Painter's Algorithm's simplicity was a big reason. The algorithm works on a **polygon-by-polygon** basis. It starts by **sorting** the polygons by their depth, from the farthest one to the nearest one and after sorting them it draws them. It has some isssues and it's not a fast algorithm since it renders every object in the scene, even the non-visible ones, but for a 3D Cube it gets the job done.
- *Easy to implement*. Implementing Painter's Algorithm was easy to implement. 

## How to Compile and Run the Simulation
### Installing SFML library 

#### (Fedora)

```
sudo dnf install SFML SFML-devel
```
#### (Debian, Ubuntu, Mint)

```
sudo apt-get install libsfml-dev
```

### Compiling the Source Code

```
g++ -Wall main.cpp RenderSim.cpp Cubo.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
Keep in mind that you have to keep all .cpp and .hpp files and the folder *files_used* in the same directory.
### Run the Simulation
```
./a.out
```
You can use -O optimization flags to get better performances, but unless you have a 25 years old PC, you won't need them.

## Planned Changes 
- Instead of using squares to render the Cube, I also plan to create a version with triangles.
- No other changes are planned.
