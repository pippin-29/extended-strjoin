# extended-strjoin
Takes a count(int), and a variable number of arguments(char *). Allocates memory and concatenates string to be returned.

uses stdarg.h (va_star, va_copy, va_end, va_arg)
makes a copy of va_list arg within the memory allocation function to preserve the list and remove the need for subsequent calls to va_start.
counts the length of each string
adds 1 and returns a pointer to the memory location to hold the string 'out'.

variable 'c' is a count of the strings that are to be entered as parameters.
this design choice was chosen over a sentinel value at the start and end, but either may work well.
In any case, the scope of this function is limited. and so it should not be hard to count the parameters entered.

# Testing So Far

Designed for a shell prompt, made up of multiple variables, and characters and colours.

```
void	store_prompt(t_prompt *prompt)
{
	prompt->prompt = strjoin_e(18 ,
				"🏠", prompt->cyan,
				prompt->username,
				prompt->white,
				"@",
				prompt->cyan, 
				prompt->hostname,
				prompt->white,
				" :: ",
				prompt->cyan, 
				basename(prompt->cwd),
				prompt->red,
				" [",
				prompt->exitstatus,
				"] ",
				"💀",
				prompt->out, prompt->green);
}	
```

Output:

🏠pippin-29@computer :: folder [2] 💀>

``./a.out 1 2 3 4 5``

54321

Parameters successfully joined into a single array, in reverse order.


``./a.out 1 2 3 4 5 | cat -e``

54321$

Parameters successfully joined into a single array, in reverse order.$
