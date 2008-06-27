#!/bin/sh

. ./mail.conf

mhonarc -spammode $MBOX -outdir $ARCHIVE
