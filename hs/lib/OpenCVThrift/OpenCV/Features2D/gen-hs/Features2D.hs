{-# LANGUAGE DeriveDataTypeable #-}
{-# LANGUAGE OverloadedStrings #-}
{-# OPTIONS_GHC -fno-warn-missing-fields #-}
{-# OPTIONS_GHC -fno-warn-missing-signatures #-}
{-# OPTIONS_GHC -fno-warn-name-shadowing #-}
{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# OPTIONS_GHC -fno-warn-unused-matches #-}

-----------------------------------------------------------------
-- Autogenerated by Thrift Compiler (1.0.0-dev)                      --
--                                                             --
-- DO NOT EDIT UNLESS YOU ARE SURE YOU KNOW WHAT YOU ARE DOING --
-----------------------------------------------------------------

module Features2D where
import Prelude ( Bool(..), Enum, Double, String, Maybe(..),
                 Eq, Show, Ord,
                 return, length, IO, fromIntegral, fromEnum, toEnum,
                 (.), (&&), (||), (==), (++), ($), (-) )

import Control.Exception
import Data.ByteString.Lazy
import Data.Hashable
import Data.Int
import Data.Text.Lazy ( Text )
import qualified Data.Text.Lazy as TL
import Data.Typeable ( Typeable )
import qualified Data.HashMap.Strict as Map
import qualified Data.HashSet as Set
import qualified Data.Vector as Vector

import Thrift
import Thrift.Types ()

import Mat_Types
import Types_Types


import Features2D_Types
import qualified Features2D_Iface as Iface
-- HELPER FUNCTIONS AND STRUCTURES --

data Detect_args = Detect_args{f_Detect_args_detectorType :: Maybe Text,f_Detect_args_image :: Maybe Mat_Types.Mat} deriving (Show,Eq,Typeable)
instance Hashable Detect_args where
  hashWithSalt salt record = salt   `hashWithSalt` f_Detect_args_detectorType record   `hashWithSalt` f_Detect_args_image record  
write_Detect_args oprot record = do
  writeStructBegin oprot "Detect_args"
  case f_Detect_args_image record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("image",T_STRUCT,-2)
    Mat_Types.write_Mat oprot _v
    writeFieldEnd oprot}
  case f_Detect_args_detectorType record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("detectorType",T_STRING,-1)
    writeString oprot _v
    writeFieldEnd oprot}
  writeFieldStop oprot
  writeStructEnd oprot
read_Detect_args_fields iprot record = do
  (_,_t3,_id4) <- readFieldBegin iprot
  if _t3 == T_STOP then return record else
    case _id4 of 
      -1 -> if _t3 == T_STRING then do
        s <- readString iprot
        read_Detect_args_fields iprot record{f_Detect_args_detectorType=Just s}
        else do
          skip iprot _t3
          read_Detect_args_fields iprot record
      -2 -> if _t3 == T_STRUCT then do
        s <- (read_Mat iprot)
        read_Detect_args_fields iprot record{f_Detect_args_image=Just s}
        else do
          skip iprot _t3
          read_Detect_args_fields iprot record
      _ -> do
        skip iprot _t3
        readFieldEnd iprot
        read_Detect_args_fields iprot record
read_Detect_args iprot = do
  _ <- readStructBegin iprot
  record <- read_Detect_args_fields iprot (Detect_args{f_Detect_args_detectorType=Nothing,f_Detect_args_image=Nothing})
  readStructEnd iprot
  return record
data Detect_result = Detect_result{f_Detect_result_success :: Maybe (Vector.Vector Types_Types.KeyPoint)} deriving (Show,Eq,Typeable)
instance Hashable Detect_result where
  hashWithSalt salt record = salt   `hashWithSalt` f_Detect_result_success record  
write_Detect_result oprot record = do
  writeStructBegin oprot "Detect_result"
  case f_Detect_result_success record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("success",T_LIST,0)
    (let f = Vector.mapM_ (\_viter7 -> Types_Types.write_KeyPoint oprot _viter7) in do {writeListBegin oprot (T_STRUCT,fromIntegral $ Vector.length _v); f _v;writeListEnd oprot})
    writeFieldEnd oprot}
  writeFieldStop oprot
  writeStructEnd oprot
read_Detect_result_fields iprot record = do
  (_,_t9,_id10) <- readFieldBegin iprot
  if _t9 == T_STOP then return record else
    case _id10 of 
      0 -> if _t9 == T_LIST then do
        s <- (let f n = Vector.replicateM (fromIntegral n) ((read_KeyPoint iprot)) in do {(_etype14,_size11) <- readListBegin iprot; f _size11})
        read_Detect_result_fields iprot record{f_Detect_result_success=Just s}
        else do
          skip iprot _t9
          read_Detect_result_fields iprot record
      _ -> do
        skip iprot _t9
        readFieldEnd iprot
        read_Detect_result_fields iprot record
read_Detect_result iprot = do
  _ <- readStructBegin iprot
  record <- read_Detect_result_fields iprot (Detect_result{f_Detect_result_success=Nothing})
  readStructEnd iprot
  return record
process_detect (seqid, iprot, oprot, handler) = do
  args <- read_Detect_args iprot
  readMessageEnd iprot
  rs <- return (Detect_result Nothing)
  res <- (do
    res <- Iface.detect handler (f_Detect_args_detectorType args) (f_Detect_args_image args)
    return rs{f_Detect_result_success= Just res})
  writeMessageBegin oprot ("detect", M_REPLY, seqid);
  write_Detect_result oprot res
  writeMessageEnd oprot
  tFlush (getTransport oprot)
proc_ handler (iprot,oprot) (name,typ,seqid) = case name of
  "detect" -> process_detect (seqid,iprot,oprot,handler)
  _ -> do
    skip iprot T_STRUCT
    readMessageEnd iprot
    writeMessageBegin oprot (name,M_EXCEPTION,seqid)
    writeAppExn oprot (AppExn AE_UNKNOWN_METHOD ("Unknown function " ++ TL.unpack name))
    writeMessageEnd oprot
    tFlush (getTransport oprot)
process handler (iprot, oprot) = do
  (name, typ, seqid) <- readMessageBegin iprot
  proc_ handler (iprot,oprot) (name,typ,seqid)
  return True