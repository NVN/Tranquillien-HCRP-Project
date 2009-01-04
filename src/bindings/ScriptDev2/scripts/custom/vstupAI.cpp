#include "precompiled.h"
 struct MANGOS_DLL_DECL vstup_AI : public ScriptedAI
      {
          vstup_AI(Creature* c) : ScriptedAI(c) { Reset(); }
      
          void Reset() { }
      
          void Aggro(Unit *who) { }
          void AttackStart(Unit* who) { }
          void MoveInLineOfSight(Unit *who)
          {
              if (who->GetTypeId() != TYPEID_PLAYER || !m_creature->IsWithinDistInMap(who, 3.0f) || !m_creature->IsWithinLOSInMap(who))
                  return;
      
              Player* player = (Player *) who;
      
              if !(player->HasItem(49)) {
                  player->CastSpellOnPlayer(40191);
              }
          }
          void UpdateAI(const uint32 diff) { }
      };
      
      CreatureAI* GetAI_vstup(Creature *_Creature)
      {
          return new vstup_AI (_Creature);
      }
void AddSC_muj_mob()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="vstup_AI";
    newscript->RegisterSelf();
}
