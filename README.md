# cscaf

'cscaf' is a command line script for generating a basic c project skeleton à la Ruby on Rails's 'scaffold'.

## Usage

The command

`$ cscaf project`

will build the following project structure after a `make`:

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
    │   ├── project_test_runner.o
    │   └── pic_project.o
    ├── shared
    │   └── libproject_shared.so
    ├── src
    │   ├── Makefile
    │   ├── project.c
    │   └── project.h
    ├── static
    │   └── libproject_static.a
    └── test
        ├── project_test
        ├── project_test.c
        └── test_runners
            └── project_test_runner.c

C_LIBRARY_HEADERS
└── project
    └── project.h

USER_BIN
└── project

C_SHARED_LIBRARIES
└── libproject_shared.so

C_STATIC_LIBRARIES
└── libproject_static.a
```

and takes care of some boilerplate in the generated files.
