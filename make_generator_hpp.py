template = """
#define GENERATOR%s( %s ) \\
   _BEGIN_GENERATOR_STATES \\
      %s \\
   _END_GENERATOR_STATES; \\
   _BEGIN_RESTORE_STATE \\
%s \\
   _END_RESTORE_STATE; \\
   _BEGIN_GENERATOR
"""
def splitby( lst, n ):
    grp = None
    for i in lst:
        if grp == None: grp = [i ]
        else: grp.append( i )
        if len( grp ) == n:
            yield grp
            grp = None
    if grp:
        yield grp

def gen( n ):
    num_cols = 5;
    state_list = []
    restore_state_list = []
    col = 0

    def statename( i ):
        return "STATE%s"%i
    states = ", ".join( map( statename, range(n) ) )

    def restore_state( i ):
        return "_RESTORE_STATE( STATE%s )"%i

    rstates = " \\\n".join(
        map(lambda grp: "      "+" ".join( grp ), 
            splitby( map( restore_state, range(n) ), 
                    num_cols) ) )

    return template%( n, states, states, rstates )

ofile = open ("_generator.hpp", "w")

ofile.write("""////////////////////////////////////////
//Utility header for the pseudo-generator
//Defiles macros for simple generator declarations
//This file is automatically generated by the script.
////////////////////////////////////////
""")
for n in range( 1, 10 ):
    ofile.write( gen( n ) )
ofile.close()
