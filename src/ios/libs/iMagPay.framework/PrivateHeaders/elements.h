#ifndef  ELEMENTS_H
#define  ELEMENTS_H

#define  MAX_ADDTAG_NUM    10

#define  FIX_LEN   0x01
#define  VAR_LEN   0x02

#define  ATTR_N    0x04
#define  ATTR_B    0x08
#define  ATTR_CN   0x10
#define  ATTR_AN   0x20
#define  ATTR_ANS  0x40

#define  IIN				 0    //0x42	Issuer Identification Number (IIN)
#define  IC_AID				 1    //0x4F	Application Identifier card
#define  APP_LABEL			 2    //0x50	Application Label
#define  TRACK2_E			 3    //0x57	Track 2 Equivalent Data
#define  PAN				 4    //0x5A    Application Primary Account
#define  ADF_FCI			 5    //0x6F	(ADF FCI) Template
#define  STEMP_1			 6    //0x71	Issuer Script Template1
#define  STEMP_2			 7    //0x72	Issuer Script Template2
#define  AMOUNT				 8    //0x81	Amount Authorised
#define  AIP				 9    //0x82	Application Interchange Profile
#define  ADF_NAME			 10   //0x84	(ADF) Name
#define  APP_PRIO			 11   //0x87	Application Priority Indicator
#define  AUTH_CODE			 12   //0x89	Authorisation Code
#define  AUTH_RESP			 13   //0x8A	Authorisation Response Code
#define  CDOL1				 14   //0x8C    (CDOL1)
#define  CDOL2				 15   //0x8D    (CDOL2)
#define  CVM				 16   //0x8E	Cardholder Verification Method (CVM)
#define  APK_ID				 17   //0x8F	Authority Public Key Index
#define  IPK_CERT			 18   //0x90	Issuer Public Key Certificate
#define  IA_DATA			 19   //0x91	Issuer Authentication Data
#define  IPK_REM			 20   //0x92	Issuer Public Key Remainder
#define  SS_APPDATA			 21   //0x93	Signed Static Application Data
#define  AFL				 22   //0x94	Application File Locator (AFL)
#define  TVR				 23   //0x95	Terminal Verification Results
#define  TDOL				 24   //0x97	(TDOL)
#define  TC					 25   //0x98	Transaction Certificate (TC)
#define  TRANS_DATE			 26   //0x9A	Transaction Date
#define  TSI				 27   //0x9B	Transaction Status Information
#define  TRANS_TYPE			 28   //0x9C	Transaction Type
#define  FCI_TEMP			 29   //0xA5	(FCI) Proprietary Template
#define  HOLDER_NAME		 30   //0x5F20	Cardholder Name
#define  EXP_DATE			 31   //0x5F24	Application Expiration Date
#define  EF_DATE			 32   //0x5F25	Application Effective Date
#define  ICON_CODE			 33   //0x5F28	Issuer Country Code
#define  TCURR_CODE			 34   //0x5F2A	Transaction Currency Code
#define  LAN_PREFER			 35   //0x5F2D	Language Preference
#define  SERV_CODE			 36   //0x5F30	Service Code
#define  PAN_SEQ			 37   //0x5F34	(PAN) Sequence
#define  TCURR_EXP			 38   //0x5F36	Transaction Currency Exponent
#define  ISSUER_URL			 39   //0x5F50	Issuer URL
#define  IBAN				 40   //0x5F53	Bank Account Number (IBAN)
#define  BIC				 41   //0x5F54	Bank Identifier Code (BIC)
#define  ICON_CODE2			 42   //0x5F55	Issuer CountryCode (alpha2 format)
#define  ICON_CODE3			 43   //0x5F56	Issuer Country Code (alpha3 format)
#define  ACCOUNT_TYPE		 44   //0x5F57	ACCOUNT TYPE
#define  ACQUIR_ID			 45   //0x9F01	Acquirer Identifier
#define  AMT_NUM			 46   //0x9F02	Amount Authorised(Numeric)
#define  AMT_OTH_NUM		 47   //0x9F03	Amount, Other(Numeric)
#define  AMT_OTH			 48   //0x9F04	Amount, Other
#define  APP_DISDATA		 49   //0x9F05	Application Discretionary Data
#define  TAID				 50   //0x9F06	Application Identifier (terminal)
#define  AUC				 51   //0x9F07	Application Usage Control
#define  APP_VER			 52   //0x9F08	Application Version Number
#define  TAPP_VER			 53   //0x9F09	Application Version Number(Terminal)
#define  HOLDER_EXT			 54   //0x9F0B	Cardholder Name Extended
#define  IACT_DEF			 55   //0x9F0D	Issuer Action Code - Default
#define  IACT_DEN			 56   //0x9F0E	Issuer Action Code - Denial
#define  IACT_LINE			 57   //0x9F0F	Issuer Action Code - Online
#define  IAPP_DATA			 58   //0x9F10	Issuer Application Data
#define  ICODE_ID			 59   //0x9F11	Issuer Code Table Index
#define  APRE_NAME			 60   //0x9F12	Application Preferred Name
#define  LATC				 61   //0x9F13	Last Online Application Transaction Counter (ATC)
#define  LOFF_LIMIT			 62   //0x9F14	Lower Consecutive Offline Limit
#define  MCATE_CODE			 63   //0x9F15	Merchant Category Code
#define  MERCH_ID			 64   //0x9F16	Merchant Identifier
#define  PTRY_CNT			 65   //0x9F17	(PIN) Try Counter
#define  TCON_CODE			 66   //0x9F1A	Terminal Country Code
#define  TFL_LIMIT			 67   //0x9F1B	Terminal Floor Limit
#define  TERM_ID			 68   //0x9F1C	Terminal Identification
#define  TRISK_DATA			 69   //0x9F1D	Terminal Risk Management Data
#define  IFD				 70   //0x9F1E	(IFD) Serial Number
#define  TRACK1				 71   //0x9F1F	Track 1
#define  TRACK2				 72   //0x9F20	Track 2
#define  TRANS_TIME			 73   //0x9F21	Transaction Time
#define  TAPK_ID			 74   //0x9F22	Authority Public Key Index(Terminal)
#define  UOFF_LIMIT			 75   //0x9F23	Upper Consecutive Offline Limit
#define  AC					 76   //0x9F26	Application Cryptogram
#define  CID				 77   //0x9F27	Cryptogram Information Data
#define  PINK_CERT			 78   //0x9F2D	Encipherment Public Key Certificate
#define  PINK_EXP			 79   //0x9F2E	Encipherment Public Key Exponent
#define  PINK_REM			 80   //0x9F2F	Encipherment Public Key Remainder
#define  IPK_EXP			 81   //0x9F32	Issuer Public Key Exponent
#define  TERM_CAP			 82   //0x9F33	Terminal Capabilities
#define  CVR				 83   //0x9F34	Cardholder Verification Results
#define  TERM_TYPE			 84   //0x9F35	Terminal Type
#define  ATC				 85   //0x9F36	Application Transaction Counter (ATC)
#define  UNPRE_NUM			 86   //0x9F37	Unpredictable Number(Terminal)
#define  PDOL				 87   //0x9F38	(PDOL)
#define  POS_Entry_Mode	     88   //0x9f39  POS Entry Mode
#define  AMT_REF			 89   //0x9F3A	Amount, Reference Currency
#define  AREF_CURR			 90   //0x9F3B	Application Reference Currency
#define  TRCURR_CODE		 91   //0x9F3C	Transaction Reference Currency Code
#define  TRCURR_EXP			 92   //0x9F3D	Transaction Reference Currency Exponent
#define  ADD_CAP			 93   //0x9F40	Additional Terminal Capabilities
#define  TSEQ_CNT			 94   //0x9F41	Transaction Sequence Counter
#define  ACURR_CODE			 95   //0x9F42	Application Currency Code
#define  ARCURR_EXP			 96   //0x9F43	Application Reference Currency Exponent
#define  ACURR_EXP			 97   //0x9F44	Application Currency Exponent
#define  DAUTH_CODE			 98   //0x9F45	Data Authentication Code
#define  ICPK_CERT			 99   //0x9F46	(ICC) Public Key Certificate
#define  ICPK_EXP			 100  //0x9F47	(ICC) Public Key Exponent
#define  ICPK_REM			 101  //0x9F48	(ICC) Public Key Remainder
#define  DDOL				 102  //0x9F49	(DDOL)
#define  SDA_TAGLIST		 103  //0x9F4A	Static Data Authentication Tag List
#define  SD_APPDATA			 104  //0x9F4B	Signed Dynamic Application Data
#define  IC_DYNUM			 105  //0x9F4C	ICC Dynamic Number
#define  LOG_ENTRY			 106  //0x9F4D	Log Entry
#define  MERCH_NAME			 107  //0x9F4E	Merchant name
#define  LOG_FMT			 108  //0x9F4F	Log Format List
#define  FCI_DISDATA		 109  //124  //0xBF0C	(FCI)Issuer Discretionary Data
#define  ELEMENTS_NUM 		 110  //125

#define SRC_TM    0  //terminal
#define SRC_ICC   1  //ICC
#define SRC_ISS   2  //issuer

typedef struct{
    int MaxLen;
    unsigned short Tag;
    unsigned short Attr;
	unsigned short usTemplate[2];
	unsigned char ucSource;
}ELEMENT_ATTR;

typedef struct{
    int DataLen;
    int UniqueFlag;
    unsigned char *Data;
}ELEMENT_DATA;

typedef struct{
    unsigned short Tag;
    int DataLen;
    unsigned char *Data;
}EXELEMENT_DATA;
 
int CheckForSelAID(unsigned char *FCI, int FCIlen);
void emvSetParamToTag(void);

#endif
























