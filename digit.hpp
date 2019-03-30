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
	if(three){
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
}