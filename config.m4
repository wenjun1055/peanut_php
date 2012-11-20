dnl $Id$
dnl config.m4 for extension peanut_php

PHP_ARG_ENABLE(peanut_php, for peanut_php support,
[  --with-peanut_php           Include peanut_php support])

if test "$PHP_PEANUT_PHP" != "no"; then

  PHP_NEW_EXTENSION(peanut_php, peanut_php.c  array.c,  $ext_shared)
fi
