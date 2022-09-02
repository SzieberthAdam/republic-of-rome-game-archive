                        ---------------------------
                        Bill's Cyberboard Utilities
                                   Readme
                        ---------------------------
                               Bill Gustafson
                                May 6, 1998
                        ---------------------------

I have written a few utilities to make creating cyberboard gamesets
easier.  I wrote these programs for my own use and as such, these
utilities are idiosyncratic, poorly tested, completed unsupported,
and without documentation.  It is not likely that this will change. 
USE AT YOUR OWN RISK!

These are win32 command-line utilities.  They should work under Windows 95,
but I haven't tested them.  They were quickly written to support 24-bit
Windows BMP files only.  I doubt that I will include support for other
bitmap types, so you will have to convert your bitmaps before using them.  

There are four programs: annotate.exe, gtltobmp.exe, scntobmp.exe, and
bmptogtl.exe.  See below for descriptions.  

Distributed Files
-----------------

The various files in found in this directory:

readme.txt    -- This file.

help.txt      -- The help output for each of the programs.  This is
also available for each program by running "programname -h."

annotate.exe  -- This program uses a configuration file that defines
an input bitmap, text and bitmaps and places them into an output
bitmap.  This allows you to create counter bitmaps, which can be made
into a gtl file using the bmptogtl.exe program.

bmptogtl.exe  -- converts a bunch of bitmaps into a Tile Library file (gtl
- see Cyberboard Release Notes for Beta 3 for a brief description) suitable
for importing into CBDesign.exe.

gtltobmp.exe  -- converts a Tile Library file (.gtl) into a bunch of
bitmaps.

scntobmp.exe  -- converts a large bitmap image (most likely scanned
in) into a set of small bitmaps, and generates a configuration file
for bmptogtl.exe.

tutorial.txt  -- a short demo of how to use the programs.  It uses the
following files:

generic.cfg   -- configuration file for annotate.exe that creates the
blue forces from the generic example gamebox file distributed with
Cyberboard.

paste.cfg     -- configuration file for annotate.exe that creates a bitmap
that mimics a scanned set of counters to demonstrate how scntobmp works.

scntobmp.cfg  -- configuration file for scntobmp.exe that "cuts up"
the demo bitmap created by using the paste.cfg file.

bmplist.txt   -- Lastly, a list of the "font" files located in the bmp
directory.

Reporting Bugs
--------------

Email any bugs you find to bill@rad.geology.washington.edu.  Keep in mind
that these programs are very simple minded, and most "bugs" are probably
unsupported features, and as such, will likely remain unsupported.

Getting Help
------------

Help for all of these programs is available by typing "programname
-h", in a DOS-Prompt in the directory where the program file is.  If
you have trouble reading the info because it scrolls off use
"programname -h | more."  This is also the entirety of the
documentation.  I have also decided to include this output in a file
called help.txt.  Please read it carefully before asking me a
question.  It is also included at the end of this file.  Since I
don't expect a lot of people to use these utilities, I will accept
email questions, although I reserve the right to ignore them.  The
price for asking a question is that I'll put my answer in a faq.txt
distributed with the program.  And if your question is about
something silly (e.g. Why doesn't the window stay up when I run the
program from the Start menu?) then your name will be enshrined
forever in the faq file.

Thanks!

Bill Gustafson
http://mycroft.geology.washington.edu/bill.htm
bill@rad.geology.washington.edu


