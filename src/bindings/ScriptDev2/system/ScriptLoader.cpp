/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"

//battlegrounds
extern void AddSC_battleground();

//custom
extern void AddSC_npc_building_mount_guard();

//world
extern void AddSC_areatrigger_scripts();
extern void AddSC_generic_creature();
extern void AddSC_go_scripts();
extern void AddSC_guards();
extern void AddSC_item_scripts();
extern void AddSC_npc_professions();
extern void AddSC_npcs_special();
extern void AddSC_spell_scripts();

void AddScripts()
{
    //battlegrounds
    AddSC_battleground();

    //custom
	AddSC_npc_building_mount_guard();

    //world
    AddSC_areatrigger_scripts();
    AddSC_generic_creature();
    AddSC_go_scripts();
    AddSC_guards();
    AddSC_item_scripts();
    AddSC_npc_professions();
    AddSC_npcs_special();
    AddSC_spell_scripts();
   
}
