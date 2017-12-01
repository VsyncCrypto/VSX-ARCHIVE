#!/bin/sh
<<<<<<< HEAD
# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> ef1718b79... Squashed 'src/univalue/' content from commit dac5296
set -e
srcdir="$(dirname $0)"
cd "$srcdir"
if [ -z ${LIBTOOLIZE} ] && GLIBTOOLIZE="`which glibtoolize 2>/dev/null`"; then
  LIBTOOLIZE="${GLIBTOOLIZE}"
  export LIBTOOLIZE
fi
<<<<<<< HEAD
which autoreconf >/dev/null || \
  (echo "configuration failed, please install autoconf first" && exit 1)
autoreconf --install --force --warnings=all
=======
autoreconf --install --force
>>>>>>> ef1718b79... Squashed 'src/univalue/' content from commit dac5296
