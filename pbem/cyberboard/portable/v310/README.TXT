                  -----------------------------
                  CyberBoard 3.10 Release Notes
                  -----------------------------
                          Dale Larson
                        January 2, 2010
                  -----------------------------

For version specific details regarding this release see the
"Release History" section in the CyberBoard help file (CBOARD.CHM)

Distributed Files
-----------------

The various files in found in this directory:

README.TXT    -- This file.

CBDesign.exe  -- This program is used to design the game boards, playing
                 pieces, markers, etc... Contains many tools for editing
                 bitmapped tiles, drawing shapes and so on.

CBPlay.exe    -- This program is used to create game scenarios and
                 actually play games.

CBoard.chm    -- The HTML help file for both programs.

Generic.gbx   -- A generic wargame with chits on a hex board.

Generic.gsn   -- A scenario for the generic wargame.

GenericGame.gam -- A demo of a game created from the Generic scenario.

CBPlayRegDel.reg -- Used to delete the CBPlay.exe program's registry key.
CBIcon.bat
desktop.ini   -- Run CBIcon.bat from the installed directory to change the
                 folder icon into the CyberBoard icon.

Version 3.10 Release Notes
--------------------------

New features and bug fixes for CBPlay.exe:

* Assign Ctrl-P hot key to start a Plotted Move, ESC cancels, and 
  Enter accepts.
* Added ability to use markers in a Plotted Move.
* Upgrade multiplayer feature to support up to 26 players. The prior
  maximum was 8 players.
* Added ability to directly transfer ownership to another player.
  Previously you had to release ownership and then assign ownership.
  A possible use for this is to make it easy to pass a card to someone.
* Prompt and create multiple markers if dragged from marker tray while 
  holding the Ctrl key. For example: If the marker tray is set to deliver 
  random markers and the markers are graphical images of dice faces you 
  essentially have created a graphical die roller.
* Change piece X & X stagger maximums from 16 to 256. This is used by the
  Autostack feature.
* The die roller has extended maximum die face value to 32767. The prior
  maximum was 100.
* Added "Select All" and "Clear All" buttons to tray import dialog in 
  scenario editor.
* Added "Select All" and "Clear All" buttons to board selection dialog 
  in scenario editor.
* 

New features for CBDesign.exe:

    * None. (Sorry)


Getting Started
---------------

The best way to get a feel for the system would probably be to replay
a game. To do this:

1) Launch CBPlay.exe
2) Open file GenericGame.gam
3) Double click on the first entry under the History section
   of the game's project window. 
4) Use the "VCR" buttons to step through the game. When you get to the
   end of the current history record (the next move button disables),
   press the Next History button. (>>)
5) When you're all done use the menu selection: Playback/Close 
   History Playback.


Reporting Bugs
--------------

Email any bugs you find to dlarson@norsesoft.com. 


Asking Questions About CyberBoard 
---------------------------------

To avoid getting bogged down with personal mail regarding CyberBoard I won't
answer questions sent this way. Please post any questions to the CyberBoardML
mailing list on groups.yahoo.com:

http://groups.yahoo.com/group/CyberBoardML/

This way everyone can learn from our discussion. Thanks!

Dale Larson
http://www.norsesoft.com/cyberboard.html
dlarson@norsesoft.com

