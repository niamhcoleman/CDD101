# CDDLabs
Labs for Concurrent Device Development

Niamh Coleman (C00205225)
License: GNU

This repo contains the labs for the concurrent device development module.

To execute run:
1) make
2) ./main

To create documentation run:
1) doxygen

## Lab 1

#### Introduction to tools

(emacs, g++, doxygen, gdb, make).

## Lab 2

#### Semaphores

Edit main.cpp so that the functions taskOne and taskTwo run in separate threads and a semaphore is used to ensure taskOne runs and exits before taskTwo.

## Lab 3

#### Rendezvous

Edit main.cpp so that a rendezvous is created using two semaphores with two threads.

## Lab 4

#### Mutual Exclusion

Demonstration of mutual exclusion using sempahore class.

## Lab 5

#### Reusable Barrier

Use of a barrier to successfully output a message in two parts.

## Lab 6

#### Producer- Consumer

A producer method that creates an event and adds it to the buffer.
A consumer method that consumes the event created by the producer.
