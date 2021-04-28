# daddyness

This is a little proof I made two years ago of a completely and utterly useless theorem regarding the number 52,
inspired by Flammable Maths in his video titled “Baking Math #2: 52” which can be found at
https://www.youtube.com/watch?v=4Uqd9QexPuA.

The definitions, theorem and proof are in `daddyness.pdf`. The proof is complemented by the programs `plot.py` and `daddyness.cpp`.

To compute the point at which the inequality (3) is violated, run:
```shell
$ python3 plot.py
```
You might have to install `numpy` and `matplotlib`.

And to get the complete list of all pseudo-daddy numbers, compile and run (here with `gcc`):
```shell
$ g++ -o daddyness daddyness.cpp && ./daddyness
```

I hope somebody will find this useful, but I highly doubt it.
