# multiline-cmdline

Constructs a command line from a multiline file, and sends it to `/bin/bash -c`.

* Lines starting with `#` are skipped. This lets you add comments and comment-out things.
* Otherwise, lines are joined, i.e., newlines simply become spaces.

Example:

```
#!/usr/bin/env mlcl
ls
# this is a comment, and the next one comments out something
# -L
-l -a
--color='never'
"${PWD}"
;
echo -e '\nCiao!\n'
```

This results in exec'ing `/bin/bash` with:

* argv[1]: `-c`
* argv[2]: `ls -l -a --color='never' "${PWD}" ; echo -e '\nCiao!\n' `
