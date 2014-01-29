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

module MatUtil where
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

import qualified Mat_Types


import MatUtil_Types
import qualified MatUtil_Iface as Iface
-- HELPER FUNCTIONS AND STRUCTURES --

data Pack_args = Pack_args{f_Pack_args_type :: Maybe CVType,f_Pack_args_matUnpacked :: Maybe Mat_Types.MatUnpacked} deriving (Show,Eq,Typeable)
instance Hashable Pack_args where
  hashWithSalt salt record = salt   `hashWithSalt` f_Pack_args_type record   `hashWithSalt` f_Pack_args_matUnpacked record  
write_Pack_args oprot record = do
  writeStructBegin oprot "Pack_args"
  case f_Pack_args_matUnpacked record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("matUnpacked",T_STRUCT,-2)
    Mat_Types.write_MatUnpacked oprot _v
    writeFieldEnd oprot}
  case f_Pack_args_type record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("type",T_I32,-1)
    writeI32 oprot (fromIntegral $ fromEnum _v)
    writeFieldEnd oprot}
  writeFieldStop oprot
  writeStructEnd oprot
read_Pack_args_fields iprot record = do
  (_,_t3,_id4) <- readFieldBegin iprot
  if _t3 == T_STOP then return record else
    case _id4 of 
      -1 -> if _t3 == T_I32 then do
        s <- (do {i <- readI32 iprot; return $ toEnum $ fromIntegral i})
        read_Pack_args_fields iprot record{f_Pack_args_type=Just s}
        else do
          skip iprot _t3
          read_Pack_args_fields iprot record
      -2 -> if _t3 == T_STRUCT then do
        s <- (read_MatUnpacked iprot)
        read_Pack_args_fields iprot record{f_Pack_args_matUnpacked=Just s}
        else do
          skip iprot _t3
          read_Pack_args_fields iprot record
      _ -> do
        skip iprot _t3
        readFieldEnd iprot
        read_Pack_args_fields iprot record
read_Pack_args iprot = do
  _ <- readStructBegin iprot
  record <- read_Pack_args_fields iprot (Pack_args{f_Pack_args_type=Nothing,f_Pack_args_matUnpacked=Nothing})
  readStructEnd iprot
  return record
data Pack_result = Pack_result{f_Pack_result_success :: Maybe Mat_Types.Mat} deriving (Show,Eq,Typeable)
instance Hashable Pack_result where
  hashWithSalt salt record = salt   `hashWithSalt` f_Pack_result_success record  
write_Pack_result oprot record = do
  writeStructBegin oprot "Pack_result"
  case f_Pack_result_success record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("success",T_STRUCT,0)
    Mat_Types.write_Mat oprot _v
    writeFieldEnd oprot}
  writeFieldStop oprot
  writeStructEnd oprot
read_Pack_result_fields iprot record = do
  (_,_t8,_id9) <- readFieldBegin iprot
  if _t8 == T_STOP then return record else
    case _id9 of 
      0 -> if _t8 == T_STRUCT then do
        s <- (read_Mat iprot)
        read_Pack_result_fields iprot record{f_Pack_result_success=Just s}
        else do
          skip iprot _t8
          read_Pack_result_fields iprot record
      _ -> do
        skip iprot _t8
        readFieldEnd iprot
        read_Pack_result_fields iprot record
read_Pack_result iprot = do
  _ <- readStructBegin iprot
  record <- read_Pack_result_fields iprot (Pack_result{f_Pack_result_success=Nothing})
  readStructEnd iprot
  return record
data Unpack_args = Unpack_args{f_Unpack_args_mat :: Maybe Mat_Types.Mat} deriving (Show,Eq,Typeable)
instance Hashable Unpack_args where
  hashWithSalt salt record = salt   `hashWithSalt` f_Unpack_args_mat record  
write_Unpack_args oprot record = do
  writeStructBegin oprot "Unpack_args"
  case f_Unpack_args_mat record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("mat",T_STRUCT,-1)
    Mat_Types.write_Mat oprot _v
    writeFieldEnd oprot}
  writeFieldStop oprot
  writeStructEnd oprot
read_Unpack_args_fields iprot record = do
  (_,_t13,_id14) <- readFieldBegin iprot
  if _t13 == T_STOP then return record else
    case _id14 of 
      -1 -> if _t13 == T_STRUCT then do
        s <- (read_Mat iprot)
        read_Unpack_args_fields iprot record{f_Unpack_args_mat=Just s}
        else do
          skip iprot _t13
          read_Unpack_args_fields iprot record
      _ -> do
        skip iprot _t13
        readFieldEnd iprot
        read_Unpack_args_fields iprot record
read_Unpack_args iprot = do
  _ <- readStructBegin iprot
  record <- read_Unpack_args_fields iprot (Unpack_args{f_Unpack_args_mat=Nothing})
  readStructEnd iprot
  return record
data Unpack_result = Unpack_result{f_Unpack_result_success :: Maybe Mat_Types.MatUnpacked} deriving (Show,Eq,Typeable)
instance Hashable Unpack_result where
  hashWithSalt salt record = salt   `hashWithSalt` f_Unpack_result_success record  
write_Unpack_result oprot record = do
  writeStructBegin oprot "Unpack_result"
  case f_Unpack_result_success record of {Nothing -> return (); Just _v -> do
    writeFieldBegin oprot ("success",T_STRUCT,0)
    Mat_Types.write_MatUnpacked oprot _v
    writeFieldEnd oprot}
  writeFieldStop oprot
  writeStructEnd oprot
read_Unpack_result_fields iprot record = do
  (_,_t18,_id19) <- readFieldBegin iprot
  if _t18 == T_STOP then return record else
    case _id19 of 
      0 -> if _t18 == T_STRUCT then do
        s <- (read_MatUnpacked iprot)
        read_Unpack_result_fields iprot record{f_Unpack_result_success=Just s}
        else do
          skip iprot _t18
          read_Unpack_result_fields iprot record
      _ -> do
        skip iprot _t18
        readFieldEnd iprot
        read_Unpack_result_fields iprot record
read_Unpack_result iprot = do
  _ <- readStructBegin iprot
  record <- read_Unpack_result_fields iprot (Unpack_result{f_Unpack_result_success=Nothing})
  readStructEnd iprot
  return record
process_pack (seqid, iprot, oprot, handler) = do
  args <- read_Pack_args iprot
  readMessageEnd iprot
  rs <- return (Pack_result Nothing)
  res <- (do
    res <- Iface.pack handler (f_Pack_args_type args) (f_Pack_args_matUnpacked args)
    return rs{f_Pack_result_success= Just res})
  writeMessageBegin oprot ("pack", M_REPLY, seqid);
  write_Pack_result oprot res
  writeMessageEnd oprot
  tFlush (getTransport oprot)
process_unpack (seqid, iprot, oprot, handler) = do
  args <- read_Unpack_args iprot
  readMessageEnd iprot
  rs <- return (Unpack_result Nothing)
  res <- (do
    res <- Iface.unpack handler (f_Unpack_args_mat args)
    return rs{f_Unpack_result_success= Just res})
  writeMessageBegin oprot ("unpack", M_REPLY, seqid);
  write_Unpack_result oprot res
  writeMessageEnd oprot
  tFlush (getTransport oprot)
proc_ handler (iprot,oprot) (name,typ,seqid) = case name of
  "pack" -> process_pack (seqid,iprot,oprot,handler)
  "unpack" -> process_unpack (seqid,iprot,oprot,handler)
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
