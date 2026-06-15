# thread_race_condition_demo
A C demo of a pthread data race on a shared string, with a writer thread and a checker that validates logged lines against a fixed sentence list.

# How to run

```bash
gcc pthread_demo.c sentences.c -pthread -o pthread_demo
./pthread_demo 
```
Then To check for race condition
```bash
gcc check.c sentences.c -o check
./check >> error.txt
cat error.txt
```
