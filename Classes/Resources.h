#ifndef _AUTO_RESOURCES_H_
#define _AUTO_RESOURCES_H_

// search paths
static const std::vector<std::string> searchPaths = {
	"fonts",
	"images",
};

// files
static const char si_CloseNormal[]		 = "CloseNormal.png"; 
static const char si_CloseSelected[]		 = "CloseSelected.png"; 
static const char sjs_file_list[]		 = "file_list.json"; 
static const char si_HelloWorld[]		 = "HelloWorld.png"; 
static const char st_MarkerFelt[]		 = "Marker Felt.ttf"; 
static const char sp_ghosts[]		 = "ghosts.plist"; 
static const char si_ghosts[]		 = "ghosts.png"; 
static const char sp_grossini_family[]		 = "grossini_family.plist"; 
static const char si_grossini_family[]		 = "grossini_family.png"; 
static const char si_JungleLeft[]		 = "JungleLeft.png"; 


////// texture //////

// ghosts.plist
static const char si_child1[]		 = "child1.gif"; 
static const char si_father[]		 = "father.gif"; 
static const char si_sister1[]		 = "sister1.gif"; 
static const char si_sister2[]		 = "sister2.gif"; 

// grossini_family.plist
static const char si_grossini[]		 = "grossini.png"; 
static const char si_grossinis_sister1[]		 = "grossinis_sister1.png"; 
static const char si_grossinis_sister2[]		 = "grossinis_sister2.png"; 

// json key
static const char file_name[]		 = "file_name"; 
static const char file_index[]		 = "file_index"; 
static const char texture_name[]		 = "texture_name"; 
static const char texture_plist[]		 = "texture_plist"; 
static const char texture_image[]		 = "texture_image"; 

#endif // _AUTO_RESOURCES_H_
