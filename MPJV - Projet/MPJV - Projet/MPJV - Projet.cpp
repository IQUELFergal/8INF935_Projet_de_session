#include <stdio.h>
#include <iostream>
#include "Particle.h"
#include "Physics.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>

int main()
{   
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    float deltaTime = 0.01f;
    
    //GLFW initialization
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(480, 480, "OpenGL Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    Physics physic = Physics();
    std::cout << "Bienvenue au stand de tir\nVeuillez choisir votre projectile.\n1 : Boulet de canon\n2 : Boule de feu\n3 : Laser\n4 : Balle\n5 : Projectile modifiable\nLes vecteurs sont au format(x,y,z)"  << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1: std::cout << "vous avez choisi le boulet de canon"<<std::endl;
        physic.addParticle(0.01, 1, Vector3D(0, 0, 0), Vector3D(1, 5, 0), Vector3D(0, 0, 0));
        break;
    case 2: std::cout << "vous avez choisi la boule de feu" << std::endl;
        physic.addParticle(0.05, 1, Vector3D(0, 0, 0), Vector3D(1, 2, 1), Vector3D(0, 0, 0));
        break;
    case 3: std::cout << "vous avez choisi le laser" << std::endl;
        physic.addParticle(10000, 1, Vector3D(0, 0, 0), Vector3D(500, 0, 0), Vector3D(0, 0, 0));
        break;
    case 4: std::cout << "vous avez choisi la balle" << std::endl;
        physic.addParticle(0.99, 1, Vector3D(0, 0, 0), Vector3D(10, 10, 0), Vector3D(0, 0, 0));
        break;
    case 5: std::cout << "vous avez choisi le projectile personnel" << std::endl;
        break;
    }
  
    //Tests physics
    /*
    physic.addParticle(0, 1, Vector3D(0, 0, 0), Vector3D(1, 0, 0), Vector3D(0, 0, 0));
    std::cout << physic.getParticle(0)->to_string() << std::endl;
    physic.update(1);
    std::cout << physic.getParticle(0)->to_string() << std::endl;
    */
    //physic.removeParticle(0);
	while (!glfwWindowShouldClose(window)) {
		//Setup View
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		
        physic.update(1);
        std::cout << physic.getParticle(0)->to_string() << std::endl;
        //permet un affichage 
        sleep_for(seconds(1));
        
        //Swap buffer and check for events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
    glfwTerminate;
    exit(EXIT_SUCCESS);

    /*
    bool run = true;
    while (run)
    {
        p2.integrate(deltaTime);
        std::cout << p2.to_string() << std::endl;
        //printf(position.to_string().c_str());*

    }*/
}



