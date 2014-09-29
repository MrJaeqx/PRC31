#ifndef MeetserieExtraH
#define MeetserieExtraH

#include "Meetserie.h"

using namespace std;

class MeetserieExtra : public Meetserie
{
  private:
    int aantalVerschillendeWaarden;
  public:
    MeetserieExtra(string nm);
    /* pre : -
       post: MeetserieExtra bevat geen meetwaarden en de
             naam van MeetserieExtra is nm
    */


    int getAantalKeer(int meetw);
    /* pre :
       post: return het aantal keer dat meetw voorkomt als meetwaarde van 
             <MeetserieExtra>
    */

    void voegToeMeetserie( Meetserie &meets );
    /* pre :
       post: Alle meetwaarden van meets zijn toegevoegd aan <MeetserieExtra>
             en het aantal verschillende waardes in <MeetserieExtra is
             bijgehouden.

    */

    void voegToe(int meetw);
    /* pre :
       post: meetwaard meetw is toegevoegd aan <MeetserieExtra>
             en het aantal verschillende waardes in <MeetserieExtra is
             bijgehouden.
    */

   int getAantalVerschillendeWaarden();
   /* pre :
      post: return het aantal verschillende waarden in <MeetserieExtra>
   */

};
#endif /* MeetserieExtraH */
