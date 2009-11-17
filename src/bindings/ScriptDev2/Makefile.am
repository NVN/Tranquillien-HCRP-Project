# Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
## Process this file with automake to produce Makefile.in

## Sub-directories to parse
SUBDIRS = sql

BUILT_SOURCES = revision.h
CLEANFILES = revision.h
## CPP flags for includes, defines, etc.
AM_CPPFLAGS = $(MANGOS_INCLUDES) -I$(srcdir) -I$(srcdir)/../../../dep/include -I$(srcdir)/../../shared/ -I$(srcdir)/../../framework/ -I$(srcdir)/../../game/ -I$(srcdir)/include/ -I$(srcdir)/base/ -DSYSCONFDIR=\"$(sysconfdir)/\"

## Build MaNGOS script library as shared library.
# libmangosscript shared library will later be reused by world server daemon.
lib_LTLIBRARIES = libmangosscript.la
libmangosscript_la_SOURCES = \
ScriptMgr.cpp \
ScriptMgr.h \
config.h \
base/escort_ai.cpp \
base/escort_ai.h \
base/follower_ai.cpp \
base/follower_ai.h \
base/guard_ai.cpp \
base/guard_ai.h \
base/simple_ai.cpp \
base/simple_ai.h \
include/precompiled.cpp \
include/precompiled.h \
include/sc_creature.cpp \
include/sc_creature.h \
include/sc_gossip.h \
include/sc_grid_searchers.cpp \
include/sc_grid_searchers.h \
include/sc_instance.cpp \
include/sc_instance.h \
scripts/battlegrounds/battleground.cpp \
scripts/custom/scriptedAI.cpp \
scripts/world/areatrigger_scripts.cpp \
scripts/world/go_scripts.cpp \
scripts/world/guards.cpp \
scripts/world/item_scripts.cpp \
scripts/world/mob_generic_creature.cpp \
scripts/world/npc_professions.cpp \
scripts/world/npcs_special.cpp \
scripts/world/spell_scripts.cpp \
system/ScriptLoader.cpp \
system/ScriptLoader.h \
system/system.cpp \
system/system.h \
revision.h


## magic to include revision data in SD2 version string
revision.h: FORCE
	$(top_builddir)/src/tools/genrevision/genrevision $(srcdir)

FORCE:

## libtool settings
# API versioning
# Link against dependencies
# How to increase version info:
# - only bug fixes implemented:
# bump the version to LTMANGOS_CURRENT:LTMANGOS_REVISION+1:LTMANGOS_AGE
# - augmented the interface:
# bump the version to LTMANGOS_CURRENT+1:0:LTMANGOS_AGE+1
# - broken old interface:
# bump the version to LTMANGOS_CURRENT+1:0:0
LTMANGOS_CURRENT = 0
LTMANGOS_REVISION = 0
LTMANGOS_AGE = 0
libmangosscript_la_LIBFLAGS = -version-info $(LTMANGOS_CURRENT):$(LTMANGOS_REVISION):$(LTMANGOS_AGE)

## Additional files to include when running 'make dist'
# Scripts defaults.
EXTRA_DIST = \
	Scripts/sc_default.cpp \
	Scripts/sc_defines.cpp \
	Scripts/sc_defines.h \
	scriptdev2.conf.dist

## Additional files to install
sysconf_DATA = \
	scriptdev2.conf.dist

install-data-hook:
	@list='$(sysconf_DATA)'; for p in $$list; do \
      dest=`echo $$p | sed -e s/.dist//`; \
	  if test -f $(DESTDIR)$(sysconfdir)/$$dest; then \
        echo "$@ will not overwrite existing $(DESTDIR)$(sysconfdir)/$$dest"; \
      else \
	    echo " $(INSTALL_DATA) $$p $(DESTDIR)$(sysconfdir)/$$dest"; \
	    $(INSTALL_DATA) $$p $(DESTDIR)$(sysconfdir)/$$dest; \
	  fi; \
	done

clean-local:
	rm -f $(sysconf_DATA)
