/**
 ** Class Items
 **/

#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Items {

        private:
        // Attribute
        Image present;
        Image slow;
        Image speed;
        Image lightning;
        Image current;
        int yPosition = 200;
        int randomItem;
        int x = 900;
        int tmp = 1;

         /******************************
          **       Constructor        **
          ******************************/
        
        public:
        Items(SVG &playground) {
            lightning = Image("/user-redirect/algoviz/img/lightning_item.png", 900, 200, 25, 25, &playground);
            speed = Image("/user-redirect/algoviz/img/speed_item.png", 900, 200, 30, 30, &playground);
            slow = Image("/user-redirect/algoviz/img/slow_item.png", 900, 200, 25, 25, &playground);
            present = Image("/user-redirect/algoviz/img/present_item.png", 900, 200, 25, 25, &playground);
            lightning.hide();
            speed.hide();
            slow.hide();
            present.hide();
        }
    
         /**************
          ** Methods **
          **************/
    
        int getXCoordinate(){
            return current.getX();
        }

        void hideCurrent(){
            current.hide();
        }
    
        void moveItem(int rndItemIndex,int y) {
            // move item to right site (back to start)
            if (x < -50){
                x = 900;
            }
          
            // re-assign current item
            if (tmp != rndItemIndex){
                if (rndItemIndex == 0){
                    current = lightning;
                } else if (rndItemIndex == 1){
                    current = slow;
                } else if (rndItemIndex == 2){
                    current = speed;
                } else if (rndItemIndex == 3){
                    current = present;
                }
                current.show();
            }
            
            current.moveTo(x, y);
            // pace
            x -= 5;
            tmp = rndItemIndex;
        }
};