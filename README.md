# cscaf

'cscaf' is a command line script for generating a basic c project skeleton à la Ruby on Rails's 'scaffold'.

## Usage

The command

`$ cscaf project`

will build the following structure in the current directory after a `make`:

```
.
└── project
    ├── LICENSE
    ├── Makefile
    ├── README.md
    ├── bin
    │   └── project
    ├── obj
    │   ├── project.o
    │   ├── project_test.o
    │   └── project_test_runner.o
    ├── src
    │   ├── Makefile
    │   ├── project.c
    │   └── project.h
    └── test
        ├── project_test
        ├── project_test.c
        └── test_runners
            └── project_test_runner.c
```

and take care of some boilerplate in the generated files.
