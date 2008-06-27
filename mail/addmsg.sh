#!/bin/sh

. `dirname $0`/mail.conf

mhonarc -add -spammode $MBOX -outdir $ARCHIVE
