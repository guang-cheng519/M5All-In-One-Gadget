#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;

const char *g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};

const char *g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_BUTTON_UP_X_CRD, MENU_BUTTON_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_BUTTON_DECIDE_X_CRD, MENU_BUTTON_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_BUTTON_DOWN_X_CRD, MENU_BUTTON_DOWN_Y_CRD);
}

void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{
    switch (current_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;
    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;
    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;
    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    }
    switch (next_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;
    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;
    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;
    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    }
    setFocusState(next_state);
}

void AppControl::displayWBGTInit()
{
}

void AppControl::displayTempHumiIndex()
{
}

void AppControl::displayMusicInit()
{
}

void AppControl::displayMusicStop()
{
}

void AppControl::displayMusicTitle()
{
}

void AppControl::displayNextMusic()
{
}

void AppControl::displayMusicPlay()
{
}

void AppControl::displayMeasureInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
    displayMeasureDistance();
}

void AppControl::displayMeasureDistance()
{

/*String distance =String(mmdist.getDistance());
int len = distance.length();
for (int i  = 0; i < len; i++) {
    distance_digit[i]=distance.charAt(i);
    delay(1);
  }
*/

    char distance_digit[4];
    int n = 0;

    int distance = (int)(mmdist.getDistance() * 10);

    while (distance != 0)
    {
        distance_digit[n] = distance % 10;
        distance /= 10;
        n++;
    }
    if (distance_digit[3] > 0)
    {
        mlcd.displayJpgImageCoordinate(*(g_str_blue + (distance_digit[3])), MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        mlcd.displayJpgImageCoordinate(*(g_str_blue + (distance_digit[2])), MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    }
    else
    {
        mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        if (distance_digit[2] > 0)
        {
            mlcd.displayJpgImageCoordinate(*(g_str_blue + (distance_digit[2])), MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
        else
        {
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
    }

    mlcd.displayJpgImageCoordinate(*(g_str_blue + (distance_digit[1])), MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(*(g_str_blue + (distance_digit[0])), MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
}

void AppControl::displayDateInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
    displayDateUpdate();
}

void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
}

void AppControl::controlApplication()
{

    mmplay.init();

    while (1)
    {

        switch (getState())
        {
        case TITLE:
            switch (getAction())
            {
            case ENTRY:
                /*
                ** まずはここにタイトル画面の表示処理を呼び出してみよう。
                ** タイトル画面表示の関数はdisplayTitleInit()である。
                ** この関数の中身はまだ何もないので、この関数にタイトル画面表示処理を書いてみよう。
                */
                displayTitleInit();
                setStateMachine(TITLE, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed || m_flag_btnB_is_pressed || m_flag_btnC_is_pressed)
                {
                    setStateMachine(TITLE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:

            switch (getAction())
            {
            case ENTRY:
                setFocusState(MENU_WBGT);
                displayMenuInit();
                setStateMachine(MENU, DO);

                break;

            case DO:
                if (m_flag_btnA_is_pressed)
                {
                    switch (getFocusState())
                    {
                    case MENU_WBGT:
                        focusChangeImg(MENU_WBGT, MENU_DATE);
                        break;
                    case MENU_MUSIC:
                        focusChangeImg(MENU_MUSIC, MENU_WBGT);
                        break;
                    case MENU_MEASURE:
                        focusChangeImg(MENU_MEASURE, MENU_MUSIC);
                        break;
                    case MENU_DATE:
                        focusChangeImg(MENU_DATE, MENU_MEASURE);
                        break;
                    }
                    setBtnAllFlgFalse();
                }
                else if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(MENU, EXIT);
                    setBtnAllFlgFalse();
                }
                else if (m_flag_btnC_is_pressed)
                {
                    switch (getFocusState())
                    {
                    case MENU_WBGT:
                        focusChangeImg(MENU_WBGT, MENU_MUSIC);
                        break;
                    case MENU_MUSIC:
                        focusChangeImg(MENU_MUSIC, MENU_MEASURE);
                        break;
                    case MENU_MEASURE:
                        focusChangeImg(MENU_MEASURE, MENU_DATE);
                        break;
                    case MENU_DATE:
                        focusChangeImg(MENU_DATE, MENU_WBGT);
                        break;
                    }
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                switch (getFocusState())
                {
                case MENU_WBGT:
                    setStateMachine(WBGT, ENTRY);
                    break;
                case MENU_MUSIC:
                    setStateMachine(MUSIC_PLAY, ENTRY);
                    break;
                case MENU_MEASURE:
                    setStateMachine(MEASURE, ENTRY);
                    break;
                case MENU_DATE:
                    setStateMachine(DATE, ENTRY);
                    break;
                }

            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction())
            {
            case ENTRY:

                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction())
            {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction())
            {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction())
            {
            case ENTRY:
                displayMeasureInit();
                setStateMachine(MEASURE, DO);
                break;

            case DO:
                displayMeasureDistance();
                delay(250);
                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(MEASURE, EXIT);
                    setBtnAllFlgFalse();
                }

                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction())
            {
            case ENTRY:
                displayDateInit();
                setStateMachine(DATE, DO);
                break;

            case DO:

                displayDateUpdate();
                delay(100);
                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(DATE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
