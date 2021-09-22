# Monty

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The project is an interpreter for Monty ByteCodes files.

## Getting Started

Ensure that you have **gcc** installed and build the program with `bash ./build.bash`. This would generate an executable called `monty`. Run the program with `./monty file`.

## Supported Opcodes

| Name | Description |
|:--:|:--|
| push | Pushes an element to the stack. Usage: `push integer` |
| pall | Prints all the values on the stack, starting from the top of the stack |
| pint | Prints the value at the top of the stack, followed by a new line |
| pop | Removes the top element of the stack |
| swap | Swaps the top two elements of the stack |
| add | Adds the top two elements of the stack |
| nop | Does nothing |
| sub | Subtracts the top element of the stack from the second top element of the stack |
| div | Divides the second top element of the stack by the top element of the stack |
| mul | Multiplies the second top element of the stack with the top element of the stack |
| mod | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| pchar | Prints the char at the top of the stack, followed by a new line |
| pstr | Prints the string starting at the top of the stack, followed by a new line |
| rotl | Rotates the stack to the top |
| rotr | Rotates the stack to the bottom |
| stack | Sets the format of the data to a stack (LIFO). This is the default behavior of the program |
| queue| Sets the format of the data to a queue (FIFO) |

## Commenting

Comments start with the `#` character after all the leading whitespaces have been skipped.

## Examples

```m
push 1
push 2
push 10
push 3
sub
pall
```

```m
push 56
push 72
pchar
```

To see more samples, visit [here](./samples)
