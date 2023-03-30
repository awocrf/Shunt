# Shunt Library

Shunt library adapted to work on my calculator project originally made by mistergreen (https://forum.arduino.cc/t/arduino-and-shunting-yard/287240/4) and modified by ZanzyTHEbar to compile correctly.

This library is a a c++ implementation of the shunt algorithm. It is a library for parsing mathematical expressions and evaluating them. It is designed to be used with Arduino, but can be used in any c++ project.

## Usage

The library is header only, so you can just include the header file in your project. The library is under the class `Shunt`.

Arduino:
```cpp
#include <Shunt.hpp>

Shunt shunt; // create the object

void setup() {
  Serial.begin(9600);
  char formula[] = "(8-4)*3+55";
  double result = shunt.shuntThis(formula); // call the method
  Serial.println(result);
}

void loop() {}
```

C++:
```cpp
#include "shunt.hpp"

int main() {
    Shunt shunt;
    char formula[] = "(8-4)*3+55";
    float result = shunt.shuntThis(formula); // call the method
    std::cout << result << std::endl;
    return 0;
}
```

## Supported operators

The library supports the following operators:

- `+` addition
- `-` subtraction
- `^` power
- `_` unary minus
- `/` division
- `*` multiplication
- `%` modulo
- `(` and `)` parenthesis
