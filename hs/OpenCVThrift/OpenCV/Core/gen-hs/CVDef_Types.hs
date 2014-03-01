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

module CVDef_Types where
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


data CVType = T8UC1|T8UC2|T8UC3|T8UC4|T8SC1|T8SC2|T8SC3|T8SC4|T16UC1|T16UC2|T16UC3|T16UC4|T16SC1|T16SC2|T16SC3|T16SC4|T32SC1|T32SC2|T32SC3|T32SC4|T32FC1|T32FC2|T32FC3|T32FC4|T64FC1|T64FC2|T64FC3|T64FC4  deriving (Show,Eq, Typeable, Ord)
instance Enum CVType where
  fromEnum t = case t of
    T8UC1 -> 0
    T8UC2 -> 1
    T8UC3 -> 2
    T8UC4 -> 3
    T8SC1 -> 4
    T8SC2 -> 5
    T8SC3 -> 6
    T8SC4 -> 7
    T16UC1 -> 8
    T16UC2 -> 9
    T16UC3 -> 10
    T16UC4 -> 11
    T16SC1 -> 12
    T16SC2 -> 13
    T16SC3 -> 14
    T16SC4 -> 15
    T32SC1 -> 16
    T32SC2 -> 17
    T32SC3 -> 18
    T32SC4 -> 19
    T32FC1 -> 20
    T32FC2 -> 21
    T32FC3 -> 22
    T32FC4 -> 23
    T64FC1 -> 24
    T64FC2 -> 25
    T64FC3 -> 26
    T64FC4 -> 27
  toEnum t = case t of
    0 -> T8UC1
    1 -> T8UC2
    2 -> T8UC3
    3 -> T8UC4
    4 -> T8SC1
    5 -> T8SC2
    6 -> T8SC3
    7 -> T8SC4
    8 -> T16UC1
    9 -> T16UC2
    10 -> T16UC3
    11 -> T16UC4
    12 -> T16SC1
    13 -> T16SC2
    14 -> T16SC3
    15 -> T16SC4
    16 -> T32SC1
    17 -> T32SC2
    18 -> T32SC3
    19 -> T32SC4
    20 -> T32FC1
    21 -> T32FC2
    22 -> T32FC3
    23 -> T32FC4
    24 -> T64FC1
    25 -> T64FC2
    26 -> T64FC3
    27 -> T64FC4
    _ -> throw ThriftException
instance Hashable CVType where
  hashWithSalt salt = hashWithSalt salt . fromEnum