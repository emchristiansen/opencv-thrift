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

module Features2D_Iface where
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
import qualified Types_Types


import Features2D_Types

class Features2D_Iface a where
  detect :: a -> Maybe Text -> Maybe Mat_Types.Mat -> IO (Vector.Vector Types_Types.KeyPoint)
  extract :: a -> Maybe Text -> Maybe Mat_Types.Mat -> Maybe (Vector.Vector Types_Types.KeyPoint) -> IO ExtractorResponse
  match :: a -> Maybe Text -> Maybe Mat_Types.Mat -> Maybe Mat_Types.Mat -> IO (Vector.Vector Types_Types.DMatch)