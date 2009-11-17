/* Copyright (C) 2009 Mordred
2        * This program is free software; you can redistribute it and/or modify
3        * it under the terms of the GNU General Public License as published by
4        * the Free Software Foundation; either version 2 of the License, or
5        * (at your option) any later version.
6        *
7        * This program is distributed in the hope that it will be useful,
8        * but WITHOUT ANY WARRANTY; without even the implied warranty of
9        * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
10       * GNU General Public License for more details.
11       *
12       * You should have received a copy of the GNU General Public License
13       * along with this program; if not, write to the Free Software
14       * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
15       */ 
      /* ScriptData
18      SDName: npc_building_mount_guard
19      SD%Complete: 100
20      SDComment: Invisible npc which dismount players
21      SDCategory: NPCs
22      EndScriptData */
      
      #include "precompiled.h"
     
      struct MANGOS_DLL_DECL npc_building_mount_guardAI : public ScriptedAI
      {
          npc_building_mount_guardAI(Creature* c) : ScriptedAI(c) { Reset(); }
      
          void Reset() { }
      
          void Aggro(Unit *who) { }
          void AttackStart(Unit* who) { }
          void MoveInLineOfSight(Unit *who)
          {
              if (who->GetTypeId() != TYPEID_PLAYER || !m_creature->IsWithinDistInMap(who, 3.0f) || !m_creature->IsWithinLOSInMap(who))
                  return;
      
              Player* player = (Player *) who;
      
              if (player->IsMounted()) {
                  player->Unmount();
                  player->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
              }
      
              if (player->HasAura(783)) {
                  player->RemoveAurasDueToSpell(783);
              }
      
              if (player->HasAura(2645)) {
                  player->RemoveAurasDueToSpell(2645);
              }
          }
          void UpdateAI(const uint32 diff) { }
      };
      
      CreatureAI* GetAI_npc_building_mount_guard(Creature *_Creature)
      {
          return new npc_building_mount_guardAI (_Creature);
      }
      
      void AddSC_npc_building_mount_guard()
      {
          Script *newscript;
      
          newscript = new Script;
          newscript->Name = "npc_building_mount_guard";
          newscript->GetAI = &GetAI_npc_building_mount_guard;
          newscript->RegisterSelf();
      }