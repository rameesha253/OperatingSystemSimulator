## **Operating System Simulator**
## **1. Project Overview**

The goal of this project is to design and implement a **simulated operating system (OS)** that demonstrates key concepts covered throughout the course. The simulator should replicate core OS functionalities such as process management, multitasking, memory allocation, interrupts, and user/kernel modes. The project offers students an opportunity to develop a miniature version of an OS environment and simulate real-time task execution.

## **2. Project Objectives**

* To simulate the working of an operating system from boot to shutdown.
* To implement multitasking with resource allocation and process scheduling.
* To demonstrate key operating system concepts like **process lifecycle**, **user/kernel modes**, **interrupt handling**, and **context switching**.
* To build an interactive environment that mimics OS functionality using either **terminal-based** or **graphical user interface** (GUI).
  

## **3. Features and Functional Requirements**

### **3.1 OS Boot and Initialization**

* The program should display the name of the custom OS using a loading screen.
* The user will specify system configuration:

  * RAM (e.g., 2 GB)
  * Hard Drive Size (e.g., 256 GB)
  * Number of CPU Cores (e.g., 8 cores)

### **3.2 Task Management**
* Users can perform at least **15 different tasks**, including:

  * Notepad with auto-save
  * Calculator
  * Displaying time and date
  * File creation, deletion, copying, and moving
  * Viewing file information
  * Minigames (e.g., Minesweeper)
* Each task must run as a **separate process**, not as a simple function call.
* Tasks will send a memory request to the OS, which checks resource availability (RAM, HDD).
* If approved, the process starts in a **new terminal window**; otherwise, it is terminated.
  

## **4. Operating Modes**

### **4.1 User Mode**

* Regular users can:

  * Start or minimize tasks.
  * View running tasks.
  * Add new tasks to the ready queue.

### **4.2 Kernel Mode**

* Kernel mode enables administrative control:

  * Force close or delete processes.
  * Reallocate resources.
  * Access hardware-level functions.


## **5. Process Lifecycle and Scheduling**

* Each task will:

  * Enter the **Ready Queue** after being created.
  * Execute based on the **CPU core availability**.
  * Use **mutual exclusion**, **semaphores**, and **condition variables** for synchronization.
  * Be scheduled using **Multilevel Queue Scheduling** with different strategies (e.g., Round Robin, FCFS).
  * On completion, release RAM and exit.

### **Interrupt Handling**

* Users can manually **interrupt** or **minimize** tasks.
* The task enters a **Blocked State** during the interrupt and resumes afterward.


## **6. Data and Memory Management**

* Each process is assigned specific memory in RAM.
* User actions like file save/store are managed through the **hard disk**.
* The system prevents overuse of RAM by limiting the number of running tasks.
* 

## **7. Task Types and Examples**

| **Type**              | **Examples**                  | **Execution Mode**      |
| --------------------- | ----------------------------- | ----------------------- |
| Full-time Interactive | Games, Notepad                | Requires constant input |
| Background            | Music player, file downloader | Runs silently           |
| Automatic             | Clock, auto-save notepad      | Runs on its own         |

* Tasks can be minimized or switched unless they are autonomous (e.g., Clock).
* Multitasking allows simultaneous execution of games, songs, calculators, and other utilities.


## **8. Project Workflow**

1. User starts the OS and configures system hardware.
2. OS boots with a welcome message.
3. Basic tasks like time/calendar start automatically.
4. User is presented with a list of available tasks.
5. Each task runs in a separate terminal and interacts with the OS via messages.
6. Interrupts and task switching are handled dynamically.
7. On shutdown, a goodbye message is shown, and all resources are freed.

## **9. Operating System Concepts Implemented**

* **Multitasking**
* **Process Creation and Termination**
* **Context Switching**
* **User and Kernel Modes**
* **Resource Allocation (RAM, HDD, Cores)**
* **EXEC Commands for Task Execution**
* **Semaphore and Condition Variable Synchronization**
* **Interrupt Handling**
* **Multilevel Queue Scheduling**

## **10. Conclusion**

This Operating System Simulator is a comprehensive practical application of the key theoretical concepts studied in the course. It promotes deeper understanding of how real OS handles processes, memory, multitasking, and user interaction, preparing students for advanced systems development in real-world scenarios.
