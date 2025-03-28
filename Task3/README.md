First of all, I've fetched the most up-to-date linux-next tag (the linux-next updates, being compiled, booted & tested daily), using:
`https://www.kernel.org/doc/man-pages/linux-next.html`

The patch includes setting EXTRAVERSION var in the main `Makefile` of the KBuild.
In addition, I was needed to alllso adapt the `.config` to not override it.

Then, I've created a patch following the guidelines in:
`https://docs.kernel.org/process/submitting-patches.html`

Of course, before submitting the patch I checked it (manually reviewing it and using the script):
`./scripts/checkpatch.pl <our-patch-path>`

Finally, you can see that before the output was:
```
➜  /boot uname -r
6.14.0-next-20250328
```

And after (compiling, using `make install` and rebooting) the output became:
```
➜  /boot uname -r
6.14.0-eudyptula-next-20250328+
```

NOTE:
In real kernel development the last phase was to check the relevant maintainers & mailing lists using:
`./scripts/get_maintainer.pl <our-patch-path>`

And then sending the actual patch mail using `git send-email` while the main maintainer would be in the `--to` and the rest (including mailing lists) would be in the `--cc`.
