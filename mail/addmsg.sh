#!/bin/sh

. ./mail.conf

mhonarc -add -spammode $MBOX -outdir $ARCHIVE
