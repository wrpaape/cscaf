# cscaf

'cscaf' is a command line script for generating a basic c project skeleton à la Ruby on Rails's 'scaffold'.

## Usage

The command

`$ cscaf project`

will build the following structure in the current directory:

```
.
└── project
    ├── LICENSE
    ├── Makefile
    ├── README.md
    ├── bin
    ├── obj
    ├── src
    │   ├── Makefile
    │   ├── project.c
    │   └── project.h
    └── test
        ├── project_test.c
```

and take care of some boilerplate in the generated files.
