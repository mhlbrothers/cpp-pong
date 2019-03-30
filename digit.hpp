void drawDigit(bool one, bool two, bool three, bool four, bool five, bool six, bool seven, float vs, float hs, float thickness, float x, float y){
    if(one){
        glBegin( GL_QUADS );
		    glVertex2f( x, y );
		    glVertex2f( x+thickness, y );
		    glVertex2f( x+thickness, y+vs/2.f );
		    glVertex2f( x, y+vs/2.f );
	    glEnd();
    }
	if(two){
        glBegin( GL_QUADS );
		    glVertex2f( x, y );
		    glVertex2f( x+hs, y );
		    glVertex2f( x+hs, y+thickness );
		    glVertex2f( x, y+thickness );
	    glEnd();
    }
	if(three){
        glBegin( GL_QUADS );
		    glVertex2f( (x+hs)-thickness, y );
		    glVertex2f( x+hs, y );
		    glVertex2f( (x+hs), y+vs/2.f );
		    glVertex2f( (x+hs)-thickness, y+vs/2.f );
	    glEnd();
    }
	if(four){
        glBegin( GL_QUADS );
		    glVertex2f( (x+hs)-thickness, y+vs/2.f );
		    glVertex2f( x+hs, y+vs/2.f );
		    glVertex2f( x+hs, y+vs );
		    glVertex2f( (x+hs)-thickness, y+vs );
	    glEnd();
    }
	if(five){
        glBegin( GL_QUADS );
		    glVertex2f( x, (y+vs)-thickness );
		    glVertex2f( x+hs, (y+vs)-thickness );
		    glVertex2f( x+hs, y+vs );
		    glVertex2f( x, y+vs );
	    glEnd();
    }
	if(six){
        glBegin( GL_QUADS );
		    glVertex2f( x, y+vs/2.f );
		    glVertex2f( x+thickness, y+vs/2.f );
		    glVertex2f( x+thickness, y+vs );
		    glVertex2f( x, y+vs );
	    glEnd();
    }
	if(seven){
        glBegin( GL_QUADS );
		    glVertex2f( x, y+vs/2.f );
		    glVertex2f( x+hs, y+vs/2.f );
		    glVertex2f( x+hs, (y+vs/2.f)+thickness );
		    glVertex2f( x, (y+vs/2.f)+thickness );
	    glEnd();
    }
}

void drawNumber(int n, float vs, float hs, float thickness, float x, float y){
	if(n == 1){
		drawDigit(false, false, true, true, false, false, false, vs, hs, thickness, x, y);
	}
	if(n == 2){
		drawDigit(false, true, true, false, true, true, true, vs, hs, thickness, x, y);
	}
	if(n == 3){
		drawDigit(false, true, true, true, true, false, true, vs, hs, thickness, x, y);
	}
	if(n == 4){
		drawDigit(true, false, true, true, false, false, true, vs, hs, thickness, x, y);
	}
	if(n == 5){
		drawDigit(true, true, false, true, true, false, true, vs, hs, thickness, x, y);
	}
	if(n == 6){
		drawDigit(true, true, false, true, true, true, true, vs, hs, thickness, x, y);
	}
	if(n == 7){
		drawDigit(false, true, true, true, false, false, false, vs, hs, thickness, x, y);
	}
	if(n == 8){
		drawDigit(true, true, true, true, true, true, true, vs, hs, thickness, x, y);
	}
	if(n == 9){
		drawDigit(true, true, true, true, true, false, true, vs, hs, thickness, x, y);
	}
	if(n == 0){
		drawDigit(true, true, true, true, true, true, false, vs, hs, thickness, x, y);
	}
}