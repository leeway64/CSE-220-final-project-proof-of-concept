# CSE-220-final-project-proof-of-concept

This project implements the circular queue as outlined in
[SWQUE: A Mode Switching Issue Queue with Priority-Correcting Circular Queue](https://dl.acm.org/doi/pdf/10.1145/3352460.3358293),
independently of the [Scarab simulator](https://github.com/Litz-Lab/scarab), as part of the final
project for CSE220.

To see the actual implementation of the project, see this [GitHub repo](https://github.com/leeway64/scarab-final-project-implementation).

## Building
```
cmake .
cmake --build .
```

## Running tests
```
./bin/unit_tests
```


## Acknowledgements
This proof-of-concept's implementation was heavily influenced by the ideas given in the
[Circular buffer Wikipedia page](https://en.wikipedia.org/wiki/Circular_buffer); refer to that page
for more information on circular buffers.
