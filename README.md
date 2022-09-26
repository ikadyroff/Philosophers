# Philosophers
This is a solution of dining philosophers problem

![image](https://user-images.githubusercontent.com/93201423/192265631-59fd06f9-a4c8-4318-bc80-d0e532915170.png)

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`
  
  # Executing
  ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>

### Ressources

* [Parallel Computing](https://computing.llnl.gov/tutorials/parallel_comp/)
* [POSIX Threads](https://computing.llnl.gov/tutorials/pthreads/) ([pthread routines](https://computing.llnl.gov/tutorials/pthreads/#AppendixA))
* [Working example](https://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/)
* [French tutorial](https://franckh.developpez.com/tutoriels/posix/pthreads/)
* [Semaphores in C](http://greenteapress.com/thinkos/html/thinkos012.html)
* [Semaphores example in French](http://jean-luc.massat.perso.luminy.univ-amu.fr/ens/docs/thread-sem.html)
* [fork() example](https://timmurphy.org/2014/04/26/using-fork-in-cc-a-minimum-working-example/)
* [fork() multiple childs](https://stackoverflow.com/questions/876605/multiple-child-process)
* [Semaphore when programs end](https://stackoverflow.com/questions/9537068/sem-close-vs-sem-unlink-when-process-terminates)
