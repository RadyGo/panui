/* 
 * File:   TouchPoint.h
 * Author: Joshua Johannson | Pancake
 *
 *
 * ---------------------------------------
 * TOUCHPOINT CLASS
 * touch point values: x,y,state
 * 
 * ---------------------------------------
 */


#ifndef TOUCHPOINT_H
#define	TOUCHPOINT_H

// include
#include <stdlib.h>
#include <functional>
#include "View.h"
#include "Ui.h"

using namespace std;
namespace ui
{

/* TouchPoint Class
 */
class TouchPoint : protected Log
{
    public:
      TouchPoint(Ui *ui);
      ~TouchPoint();
      
      // position, read only
      float x, y;

      // last drag scroll pos
      Point lastScroll;

      /* state, read only
       * @param STATE_UP or STATE_DOWN */
      bool state;
      
      
      // finger/mouse pressed
      void press(int button, int type);
      
      // move point
      void move(float x, float y);

      // on scroll
      void scroll(float x, float y);
      
      // views add themselves when isOver
      //void addOver(View *view);

      // views remove themselves when not isOver
      //void removeOver(View *view);
      
      // state values
      static bool STATE_DOWN;
      static bool STATE_UP;
            
    
      // uis root view
      Ui *ui;
      
      // actual top view point is over
      View *over;
      
      // actual view touch on top is down
      View *down;

      // actual view is focused
      View *focus;
      
      // actual views point is over
      //list<View*> overList;


    private:
        void eachView(View *container,function<void (View *view)> func);
};


};     /* END NAMESPACE */
#endif	/* TOUCHPOINT_H */

