#if !defined(DIALOG_H)
#define DIALOG_H

#include <stdlib.h>

typedef struct DialogStruct
{
    char* text;
    // two choices
    char* choice1;
    char* choice2;
    struct DialogStruct* next1;
    struct DialogStruct* next2;
    // custom function for doing things
    // will be executed if not null
    void (*effect)(struct DialogStruct* self);
} Dialog;


Dialog* Dialog_new(Dialog* self){
    Dialog* dialog = self;
    if (dialog == NULL)
    {
        dialog = calloc(1, sizeof(Dialog));
    }
    
    dialog->text = NULL;
    dialog->choice1 = NULL;
    dialog->choice2 = NULL;
    dialog->next1 = NULL;
    dialog->next2 = NULL;
    dialog->effect = NULL;
}

#endif // DIALOG_H
