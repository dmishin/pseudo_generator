////////////////////////////////////////
//Utility header for the pseudo-generator
//Defiles macros for simple generator declarations
//This file is automatically generated by the script.
////////////////////////////////////////

#define BEGIN_GEN1( STATE0 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN2( STATE0, STATE1 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN3( STATE0, STATE1, STATE2 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN4( STATE0, STATE1, STATE2, STATE3 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2, STATE3 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) _RESTORE_STATE( STATE3 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN5( STATE0, STATE1, STATE2, STATE3, STATE4 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2, STATE3, STATE4 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) _RESTORE_STATE( STATE3 ) _RESTORE_STATE( STATE4 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN6( STATE0, STATE1, STATE2, STATE3, STATE4, STATE5 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2, STATE3, STATE4, STATE5 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) _RESTORE_STATE( STATE3 ) _RESTORE_STATE( STATE4 ) \
      _RESTORE_STATE( STATE5 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN7( STATE0, STATE1, STATE2, STATE3, STATE4, STATE5, STATE6 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2, STATE3, STATE4, STATE5, STATE6 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) _RESTORE_STATE( STATE3 ) _RESTORE_STATE( STATE4 ) \
      _RESTORE_STATE( STATE5 ) _RESTORE_STATE( STATE6 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN8( STATE0, STATE1, STATE2, STATE3, STATE4, STATE5, STATE6, STATE7 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2, STATE3, STATE4, STATE5, STATE6, STATE7 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) _RESTORE_STATE( STATE3 ) _RESTORE_STATE( STATE4 ) \
      _RESTORE_STATE( STATE5 ) _RESTORE_STATE( STATE6 ) _RESTORE_STATE( STATE7 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR

#define BEGIN_GEN9( STATE0, STATE1, STATE2, STATE3, STATE4, STATE5, STATE6, STATE7, STATE8 ) \
   _BEGIN_GENERATOR_STATES \
      STATE0, STATE1, STATE2, STATE3, STATE4, STATE5, STATE6, STATE7, STATE8 \
   _END_GENERATOR_STATES; \
   _BEGIN_RESTORE_STATE \
      _RESTORE_STATE( STATE0 ) _RESTORE_STATE( STATE1 ) _RESTORE_STATE( STATE2 ) _RESTORE_STATE( STATE3 ) _RESTORE_STATE( STATE4 ) \
      _RESTORE_STATE( STATE5 ) _RESTORE_STATE( STATE6 ) _RESTORE_STATE( STATE7 ) _RESTORE_STATE( STATE8 ) \
   _END_RESTORE_STATE; \
   _BEGIN_GENERATOR
