; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "ArbolTernario"
#define MyAppVersion "1.0"
#define MyAppPublisher "None"
#define MyAppExeName "ArbolTernarioBusqueda.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{4D3DE511-081A-4EB4-ABD3-1044E9F5199D}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName=D:\Patricio\Documents\GitHub\EstructuraDeDatosProyectoP2\ProyectoArbolTrinario\Instalador\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=setup
Password=A1B2-C3D4-E5F6-G7H8-I9J0
Compression=lzma
SolidCompression=yes

[Languages]
Name: "default"; MessagesFile: "compiler:Default.isl"
Name: "english"; MessagesFile: "compiler:Languages\English.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\Patricio\Documents\GitHub\EstructuraDeDatosProyectoP2\ProyectoArbolTrinario\ArbolTernarioBusqueda.exe"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[ISFormDesigner]
WizardForm=FF0A005457495A415244464F524D0030100902000054504630F10B5457697A617264466F726D0A57697A617264466F726D0C436C69656E744865696768740368010B436C69656E74576964746803F1010C4578706C696369744C65667402000B4578706C69636974546F7002000D4578706C6963697457696474680301020E4578706C69636974486569676874038E010D506978656C73506572496E636802600A54657874486569676874020D00F10C544E65774E6F7465626F6F6B0D4F757465724E6F7465626F6F6B00F110544E65774E6F7465626F6F6B506167650B57656C636F6D65506167650D4578706C69636974576964746803F1010E4578706C696369744865696768740339010000F110544E65774E6F7465626F6F6B5061676509496E6E6572506167650D4578706C69636974576964746803F1010E4578706C6963697448656967687403390100F10C544E65774E6F7465626F6F6B0D496E6E65724E6F7465626F6F6B00F110544E65774E6F7465626F6F6B506167650B4C6963656E7365506167650D4578706C69636974576964746803A1010E4578706C6963697448656967687403ED000000F110544E65774E6F7465626F6F6B506167650C50617373776F7264506167650D4578706C69636974576964746803A1010E4578706C6963697448656967687403ED0000F10D5450617373776F7264456469740C50617373776F7264456469740850617373776F72640800000000000000

[Code]
{ RedesignWizardFormBegin } // Don't remove this line!
// Don't modify this section. It is generated automatically.
procedure RedesignWizardForm;
begin
  with WizardForm.PasswordEdit do
  begin
    Password := False;
  end;

{ ReservationBegin }
  // This part is for you. Add your specialized code here.

{ ReservationEnd }
end;
// Don't modify this section. It is generated automatically.
{ RedesignWizardFormEnd } // Don't remove this line!

procedure InitializeWizard();
begin
  RedesignWizardForm;
end;




