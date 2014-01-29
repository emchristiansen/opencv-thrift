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

module MatUtil_Client(MatUtil_Client.pack,MatUtil_Client.unpack) where
import Data.IORef
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
import MatUtil
seqid = newIORef 0
pack (ip,op) arg_type arg_matUnpacked = do
  send_pack op arg_type arg_matUnpacked
  recv_pack ip
send_pack op arg_type arg_matUnpacked = do
  seq <- seqid
  seqn <- readIORef seq
  writeMessageBegin op ("pack", M_CALL, seqn)
  write_Pack_args op (Pack_args{f_Pack_args_type=Just arg_type,f_Pack_args_matUnpacked=Just arg_matUnpacked})
  writeMessageEnd op
  tFlush (getTransport op)
recv_pack ip = do
  (fname, mtype, rseqid) <- readMessageBegin ip
  if mtype == M_EXCEPTION then do
    x <- readAppExn ip
    readMessageEnd ip
    throw x
    else return ()
  res <- read_Pack_result ip
  readMessageEnd ip
  case f_Pack_result_success res of
    Just v -> return v
    Nothing -> do
      throw (AppExn AE_MISSING_RESULT "pack failed: unknown result")
unpack (ip,op) arg_mat = do
  send_unpack op arg_mat
  recv_unpack ip
send_unpack op arg_mat = do
  seq <- seqid
  seqn <- readIORef seq
  writeMessageBegin op ("unpack", M_CALL, seqn)
  write_Unpack_args op (Unpack_args{f_Unpack_args_mat=Just arg_mat})
  writeMessageEnd op
  tFlush (getTransport op)
recv_unpack ip = do
  (fname, mtype, rseqid) <- readMessageBegin ip
  if mtype == M_EXCEPTION then do
    x <- readAppExn ip
    readMessageEnd ip
    throw x
    else return ()
  res <- read_Unpack_result ip
  readMessageEnd ip
  case f_Unpack_result_success res of
    Just v -> return v
    Nothing -> do
      throw (AppExn AE_MISSING_RESULT "unpack failed: unknown result")
