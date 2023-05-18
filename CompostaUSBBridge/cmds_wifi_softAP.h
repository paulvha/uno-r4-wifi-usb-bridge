#ifndef CMDS_WIFI_SOFTAP_H
#define CMDS_WIFI_SOFTAP_H


#include "at_handler.h"

void CAtHandler::add_cmds_wifi_softAP() {
   
   /* ....................................................................... */
   command_table[_BEGINSOFTAP] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      switch (parser.cmd_mode) {
           case chAT::CommandMode::Write: {
               if (parser.args.size() <= 0 || parser.args.size() > 5) {
                 return chAT::CommandStatus::ERROR;
               }
               const char * ssid = NULL;
               const char * passphrase = NULL;
               int ch  = 1;
               bool ssid_hidden = false;
               int max_connection = 5;
               switch (parser.args.size()) {
                 case 5: {
                     auto &_max_connection = parser.args[4];
                     if (_max_connection.empty()) {
                       return chAT::CommandStatus::ERROR;
                     }
                     max_connection = atoi(_max_connection.c_str());
                   }
                 case 4: {
                     auto &_ssid_hidden = parser.args[3];
                     if (_ssid_hidden.empty()) {
                       return chAT::CommandStatus::ERROR;
                     }
                     ssid_hidden = atoi(_ssid_hidden.c_str());
                   }
                 case 3: {
                     auto &_ch = parser.args[2];
                     if (_ch.empty()) {
                       return chAT::CommandStatus::ERROR;
                     }
                     ch = atoi(_ch.c_str());
                   }
                 case 2: {
                     auto &_passphrase = parser.args[1];
                     if (_passphrase.empty()) {
                       return chAT::CommandStatus::ERROR;
                     }
                     passphrase = _passphrase.c_str();
                   }
                 case 1: {
                     auto &_ssid = parser.args[0];
                     if (_ssid.empty()) {
                       return chAT::CommandStatus::ERROR;
                     }
                     ssid = _ssid.c_str();
                     break;
                   }
                 default: {
                     return chAT::CommandStatus::ERROR;
                   }
               }

               WiFi.softAP(ssid, passphrase, ch, ssid_hidden, max_connection);
               return chAT::CommandStatus::OK;
             }
           default:
             return chAT::CommandStatus::ERROR;
         }
   };

   /* ....................................................................... */
   command_table[_DISCONNECTSOFTAP] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      switch (parser.cmd_mode) {
           case chAT::CommandMode::Run: {
               WiFi.softAPdisconnect();
               return chAT::CommandStatus::OK;
             }
           case chAT::CommandMode::Write: {
               if (parser.args.size() != 1) {
                 return chAT::CommandStatus::ERROR;
               }

               auto &wifi_off = parser.args[0];
               if (wifi_off.empty()) {
                 return chAT::CommandStatus::ERROR;
               }
               WiFi.softAPdisconnect(atoi(wifi_off.c_str()));
               return chAT::CommandStatus::OK;
             }
           default:
             return chAT::CommandStatus::ERROR;
         }
   };


   /* ....................................................................... */
   command_table[_MACSOFTAP] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      switch (parser.cmd_mode) {
           case chAT::CommandMode::Read: {
               srv.write_response_prompt();
               String ap_mac = WiFi.softAPmacAddress();
               srv.write_str((const char *)(ap_mac.c_str()));

               return chAT::CommandStatus::OK;
             }
           default:
             return chAT::CommandStatus::ERROR;
         }
       }
   };

   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };
   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };
   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };
   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };
   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };
   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };
   /* ....................................................................... */
   command_table[ ] = [this](auto & srv, auto & parser) {
   /* ....................................................................... */     
      
   };

 
}